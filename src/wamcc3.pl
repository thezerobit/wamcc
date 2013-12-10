/*-------------------------------------------------------------------------*/
/* Passe 3: Classification des variables,                                  */
/*          allocation des variables permanentes,                          */
/*          calcul des informations pour le trimming (Trimming).           */
/*                                                                         */
/* predicat d'appel: classif_variables(T,C)                                */
/*                                                                         */
/* entree-sortie                                                           */
/* T: format interne de la tete (on va lier certaines variables libres)    */
/* C: format interne du corps   (on va lier certaines variables libres)    */
/*                                                                         */
/*                                                                         */
/* On utilise une variable NoY pour connaitre le prochain numero utilisable*/
/* a affecter a la prochaine (dans l'ordre ci-dessous) variable permanente.*/
/* Les variables sont numerotees a partir de 0.                            */
/*                                                                         */
/* Principe:                                                               */
/* Les fausses permanentes (var n'apparaissant que dans un but mais qui ne */
/* n'ont pas leur 1ere occ. en tete, en structure ou dans le dernier but), */
/* doivent etre numerotees avant les vraies (si WarrenTmp=t bien sur, sinon*/
/* ces variables sont des temporaires). Option WarrenTmp supprime: tjs f   */
/* En effet, on ne peut effectuer de trimming sur de telles variables,     */
/* puisque leur premiere occurrence va donner lieu a put_y_variable(Ai) qui*/
/* liera Ai avec l'environnement.                                          */
/*                                                                         */
/* On traite la clause de la droite vers la gauche (corps avant tete), et  */
/* pour chaque predicat, on traite ses arguments de la droite vers la      */
/* et en profondeur d'abord.                                               */
/* Lorsque une vraie permanente est rencontree (deja unifiee a y(No)),     */
/* on place No dans la liste des variables a allouer (LYAAlloc). On leur   */
/* allouera un numero apres avoir traite toutes les fausse permanentes.    */
/*                                                                         */
/* Traitement des variables:                                               */
/*                                                                         */
/* soit var(igv(Nom,NoPPOcc,NoPDOcc,Stc,Unsafe),PremOcc,DernOcc) l'occ.    */
/* et NoPred le numero du predicat courant (qui contient cette occurrence) */
/*                                                                         */
/* Si libre(Nom)                                                           */
/*    Alors                                                                */
/*       Si WarrenTmp=f                                                    */
/*          Alors                                                          */
/*             Nom=x(_)                  % = represente l'unification      */
/*          Sinon                                                          */
/*             Nom=y(NoY)                % fausse permanente               */
/*             Inc(NoY)                                                    */
/*             Unsafe=f                  % pas de put_y_unsafe_value car   */
/*          FinSi                        % pas de trimming sur fausse perm */
/*                                                                         */
/*       DernOcc=t                                                         */
/*       NoPDOcc=NoPred                  % aussi egal a NoPPOcc evidement  */
/*    Sinon                                                                */
/*       Si Nom=y(No) Et libre(NoPDOcc)                                    */
/*          Alors                        % vraie permanente                */
/*             DernOcc=t                                                   */
/*             NoPDOcc=NoPred                                              */
/*             Ajout de No a LYAAlloc                                      */
/*          Sinon                                                          */
/*             DernOcc=f                 % pas dern occ de y(_) ou de x(_) */
/*          FinSi                                                          */
/*    FinSi                                                                */
/*                                                                         */
/* En ce qui concerne le trimming, pour chaque predicat, le nombre de var  */
/* permanentes necessaires apres son effacement (Trimming) est egal a la   */
/* valeur courante de NoY, AVANT l'allocation des var en LYAAlloc.         */
/*                                                                         */
/* Il ne reste qu'a allouer un numero aux vraies permanentes en partant de */
/* la fin vers le debut. Ce qui revient a lier chaque variable de LYAAlloc */
/* a la valeur courante de NoY et a incrementer celui-ci.                  */
/*-------------------------------------------------------------------------*/

:- public classif_variables/2.

classif_variables(T,C):-
	classif_corps(C,NoY),
	classif_tete(T,NoY).




classif_tete(Pred,NoY):-
	classif_pred(Pred,NoY,_).




classif_corps([],0).

classif_corps([Pred|C],NoY1):-
	classif_corps(C,NoY),
	classif_pred(Pred,NoY,NoY1).




classif_pred(p(NoPred,_,LstArg,NoY1),NoY,NoY2):-
	classif_lst_arg(LstArg,NoPred,NoY,NoY1,[],LYAAlloc),
	alloc_vraies_varsY(LYAAlloc,NoY1,NoY2).




classif_lst_arg([],_,NoY,NoY,LYAAlloc,LYAAlloc).

classif_lst_arg([Arg|LstArg],NoPred,NoY,NoY2,LYAAlloc,LYAAlloc2):-
	classif_lst_arg(LstArg,NoPred,NoY,NoY1,LYAAlloc,LYAAlloc1),
	classif_arg(Arg,NoPred,NoY1,NoY2,LYAAlloc1,LYAAlloc2),
	!.




classif_arg(var(igv(Nom,_,NoPred,_,_),_,t),NoPred,NoY,NoY,LYAAlloc,LYAAlloc):-
	var(Nom),
	Nom=x(_).                           % Unsafe inutilise si x(_)

classif_arg(var(igv(y(No),_,NoPDOcc,_,_),_,t),NoPred,NoY,NoY,
	LYAAlloc,[No|LYAAlloc]):-
	 var(NoPDOcc),                       % pour ne la mettre qu'une
	 NoPDOcc=NoPred.                     % fois en LYAAlloc 

classif_arg(var(_,_,f),_,NoY,NoY,LYAAlloc,LYAAlloc).

classif_arg(nil,       _,NoY,NoY,LYAAlloc,LYAAlloc).

classif_arg(cst(_),    _,NoY,NoY,LYAAlloc,LYAAlloc).

classif_arg(int(_),    _,NoY,NoY,LYAAlloc,LYAAlloc).

classif_arg(lst(Car,Cdr),NoPred,NoY,NoY1,LYAAlloc,LYAAlloc1):-
	classif_lst_arg([Car,Cdr],NoPred,NoY,NoY1,LYAAlloc,LYAAlloc1).

classif_arg(stc(_,LstArg),NoPred,NoY,NoY1,LYAAlloc,LYAAlloc1):-
	classif_lst_arg(LstArg,NoPred,NoY,NoY1,LYAAlloc,LYAAlloc1).



	                                % Temporaire Warren:
temporaire(0,_,_).                      % si 1ere occ. en tete OU

temporaire(_,t,_).                      % si 1ere occ. en structure OU

temporaire(N,_,N).                      % si 1ere occ. en dernier but




alloc_vraies_varsY([],NoY,NoY).

alloc_vraies_varsY([NoY1|LYAAlloc],NoY,NoY2):-
	alloc_vraies_varsY(LYAAlloc,NoY,NoY1),
	NoY2 is NoY1+1.

