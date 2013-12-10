/*-------------------------------------------------------------------------*/
/* Generation de l'indexation en 2 niveaux et emission du code.            */
/*                                                                         */
/* Niveau 1:                                                               */
/* Les clauses C1,...,Cn d'un predicat Pred sont eclatees en groupes       */
/* G0,...,Gm tq chaque groupe Gi:                                          */
/*   a) ne contient qu'une clause dont le 1er arg. est une variable.       */
/*   b) ne contient que des clauses dont le 1er arg. n'est pas une var.    */
/* Le code suivant est alors genere:                                       */
/*                                                                         */
/*   L0: try_me_else(L1)                                                   */
/*       <code pour G0>                                                    */
/*                                                                         */
/*   L1: retry_me_else(L2)                                                 */
/*       <code pour G1>                                                    */
/*            :                                                            */
/*            :                                                            */
/*   Lm: trust_me_else_fail                                                */
/*       <code pour Gm>                                                    */
/*                                                                         */
/* Niveau 2:                                                               */
/* Dans le cas d'un groupe Gi du type a, le <code pour Gi> ne contient que */
/* le code wam issu de la compilation de la clause Ck associee.            */
/* Dans le cas d'un groupe Gi du type b, le <code pour Gi> contient les    */
/* instructions d'indexation du niveau 2 pour discriminer entre les        */
/* constantes, les listes et les structures.                               */
/* L'indexation est realisee par:                                          */
/*                                                                         */
/*            switch_on_term(LabVar,LabCst,LabLst,LabStc)                  */
/*                                                                         */
/*   LabFail: fail             si LabCst ou LabLst ou LabStc = LabFail     */
/*                                                                         */
/*   LabCst : switch_on_constant(N,[(cst1,LabCst1),...(cstN,LabCstN)])   \ */
/*                                                                       | */
/*   LabCstj: try(Adj1)                  \  si plus d'une clause a cstj  | */
/*            retry(Adj2)  si + de 2     |  comme 1er arg,               | */
/*              :                        |  sinon LabCstj = Adj1         | */
/*            trust(Adjk)                /                               | */
/*                                 s'il y a des cst, sinon LabCst=LabFail/ */
/*   idem pour switch_on_integer                                           */
/*                                                                         */
/*   LabLst : try(Adj1)                  \  si plus d'une clause a [_|_] \ */
/*            retry(Adj2)  si + de 2     |  comme 1er arg,               | */
/*              :                        |  sinon LabLst = Adj1          | */
/*            trust(Adjk)                /                               | */
/*                                 s'il y a des lst, sinon LabLst=LabFail/ */
/*                                                                         */
/*   LabStc : switch_on_structure(N,[(stc1,LabStc1),...(cstN,LabStcN)])  \ */
/*                                                                       | */
/*   LabStcj: try(Adj1)                  \  si plus d'une clause a stcj  | */
/*            retry(Adj2)  si + de 2     |  comme 1er arg,               | */
/*              :                        |  sinon LabStcj = Adj1         | */
/*            trust(Adjk)                /                               | */
/*                                 s'il y a des stc, sinon LabStc=LabFail/ */
/*                                                                         */
/*   LabVar:  try_me_else(LabVar2) s'il y a plus d'une clause dans Gi,     */
/*   Ad1:     <code clause 1>      sinon LabVar = Ad1                      */
/*                                                                         */
/*   LabVar2: retry_me_else(LabVar3)                                       */
/*   Ad2:     <code clause 2>                                              */
/*                :                                                        */
/*                :                                                        */
/*   LabVarp: trust_me_else_fail                                           */
/*   Adp:     <code clause p>                                              */
/*                                                                         */
/* Implantation:                                                           */
/*                                                                         */
/* predicat d'appel: indexation(LCl,LClW)                                  */
/*                                                                         */
/* entree                                                                  */
/* LCl    : [cl(Ad,Arg1,W), ...] liste clauses compilees du predicat Pred  */
/*                                                                         */
/*       Ad  : contiendra en niveau 2 le label associe a la liste d'inst W */
/*             (a l'appel: var libre)                                      */
/*       Arg1: le premier argument de la clause source (cf comment passe 2)*/
/*       W   : [inst_wam, ...] inst wam associees a la clause              */
/*                                                                         */
/*                                                                         */
/* sortie                                                                  */
/* LClW: [[inst_wam, ...], ...] code wam total (avec inst d'indexation).   */
/*       Pour eviter des append, il se peut que LClW contienne des listes  */
/*       imbriquees. C'est au moment de l'emission vers un fichier qu'il   */
/*       faudra applatir la liste LClW.                                    */
/*                                                                         */
/* cherche_var partitionne LCl en LClAv ClVar et LClAp et detecte dans     */
/* quel Cas on est:                                                        */
/*                                                                         */
/*   1...) une variable a ete trouvee (donc niveau 1), sous cas:           */
/*      11) LClAv<>[] et LClAp<>[]       12) LClAv<>[] et LClAp=[]         */
/*      13) LClAv= [] et LClAp<>[]       14) LClAv= [] et LClAp=[]         */
/*                                                                         */
/*   2) pas de variable (donc niveau 2)                                    */
/*                                                                         */
/* Autres variables utilisees:                                             */
/*                                                                         */
/* Niv1 : a t'on a deja genere des try/retry/trust_me_else du niv 1 (t/f) ?*/
/* Cst  : [a(cst,[Ad, ...]), ...]                                          */
/* Int  : [a(int,[Ad, ...]), ...]                                          */
/* Lst  : [Ad, ...]                                                        */
/* Stc  : [a(f/n,[Ad, ...]), ...]                                          */
/*        ajout en fin des listes [Ad, ...] par methode des listes         */
/*        terminees par une variable (Fin) (en decouper/4, etc).           */
/* Liste: Cst, Int, ou Stc pour traitement commun                          */
/*-------------------------------------------------------------------------*/

:- public indexation/2.

indexation(LCl,LClW):-
	indexation1(LCl,f,_,LClW),
	alloc_labels(LClW,0,_).



indexation1(LCl,Niv1,Lab,[label(Lab)|LClW]):-
	cherche_var(LCl,Cas,LClAv,ClVar,LClAp),
	indexer(Cas,LClAv,ClVar,LClAp,Niv1,LClW),
	!.




cherche_var([],2,[],_,[]).

cherche_var([cl(Ad,Arg1,W)|LCl],Cas,[],cl(Ad,Arg1,W),LCl):-
	var(Arg1), 
	(LCl==[] -> Cas=14
	         ;  Cas=13).

cherche_var([Cl|LCl],Cas1,[Cl|LClAv],ClVar,LClAp):-
	cherche_var(LCl,Cas,LClAv,ClVar,LClAp),
	(Cas==13 -> Cas1=11
	         ;  (Cas==14 -> Cas1=12
	                     ;  Cas1=Cas)).




indexer(11,LClAv,cl(_,_,W),LClAp,Niv1,LClW):-
	(Niv1==f -> TmRmTm=try_me_else(Lab)
	         ;  TmRmTm=retry_me_else(Lab)),
	indexer(2,LClAv,_,_,f,LClAvW),
	indexation1(LClAp,t,Lab1,LClApW),
	LClW=[TmRmTm,LClAvW,label(Lab),retry_me_else(Lab1),W|LClApW].

indexer(12,LClAv,cl(_,_,W),_,Niv1,LClW):-
	(Niv1==f -> TmRmTm=try_me_else(Lab)
	         ;  TmRmTm=retry_me_else(Lab)),
	indexer(2,LClAv,_,_,f,LClAvW),
	LClW=[TmRmTm,LClAvW,label(Lab),trust_me_else_fail|W].

indexer(13,_,cl(_,_,W),LClAp,Niv1,LClW):-
	(Niv1==f -> TmRmTm=try_me_else(Lab)
	         ;  TmRmTm=retry_me_else(Lab)),
	indexation1(LClAp,t,Lab,LClApW),
	LClW=[TmRmTm,W|LClApW].

indexer(14,_,cl(_,_,W),_,Niv1,LClW):-
	(Niv1==f -> LClW=W 
	         ;  LClW=[trust_me_else_fail|W]).

indexer(2,LCl,_,_,Niv1,LClW):-
	(Niv1==f -> LClW=[switch_on_term(LabVar,LabCst,LabInt,
	                                 LabLst,LabStc)|W1]
	         ;  LClW=[trust_me_else_fail,
	                  switch_on_term(LabVar,LabCst,LabInt,
	                                 LabLst,LabStc)|W1]),
	decouper(LCl,Cst,Int,Lst,Stc),
	!,
	(Cst==[] -> LabCst=LabFail, Fail=t
	         ;  true),
	(Int==[] -> LabInt=LabFail, Fail=t
	         ;  true),
	(Lst==[] -> LabLst=LabFail, Fail=t
	         ;  true),
	(Stc==[] -> LabStc=LabFail, Fail=t
	         ;  true),
	(Fail==t -> W1=SwtCstW,
	            LabFail=fail  /* ou W1=[label(LabFail),fail|SwtCstW] */
	         ;
		     W1=SwtCstW),
	gen_switch(Cst,switch_on_constant,LabCst,SwtIntW,SwtCstW),!,
	gen_switch(Int,switch_on_integer, LabInt,LstW,SwtIntW),   !,
	gen_liste(Lst,LabLst,SwtStcW,LstW),                       !,
	gen_switch(Stc,switch_on_structure,LabStc,W2,SwtStcW),    !,
	gen_insts(LCl,LabVar,W2),                                 !.




decouper(LCl,Cst1,Int1,Lst,Stc1):- 
	decouper1(LCl,[],[],a(Fin,Fin),[],Cst,Int,a([],Lst),Stc),
	finir_liste(Cst,Cst1),
	finir_liste(Int,Int1),
	finir_liste(Stc,Stc1).


decouper1([],Cst,Int,Lst,Stc,Cst,Int,Lst,Stc).

decouper1([cl(Ad,Arg1,_)|LCl],Cst,Int,Lst,Stc,Cst2,Int2,Lst2,Stc2):-
	decouper2(Arg1,Ad,Cst,Int,Lst,Stc,Cst1,Int1,Lst1,Stc1),
	decouper1(LCl,Cst1,Int1,Lst1,Stc1,Cst2,Int2,Lst2,Stc2).


decouper2(F/0,Ad,Cst,Int,Lst,Stc,Cst1,Int1,Lst,Stc):-
	type_atomic(F,T),                                        % cf passe 2
	(T==cst(F) -> ajout_en_liste(Cst,F,Ad,Cst1), 
	              Int1=Int
	           ;
	              ajout_en_liste(Int,F,Ad,Int1), 
	              Cst1=Cst).

decouper2('.'/2,Ad,Cst,Int,a([Ad|Fin],LAd),Stc,Cst,Int,a(Fin,LAd),Stc).

decouper2(F/N,Ad,Cst,Int,Lst,Stc,Cst,Int,Lst,Stc1):-
	ajout_en_liste(Stc,F/N,Ad,Stc1).



ajout_en_liste([],F,Ad,[a(F,Fin,[Ad|Fin])]).

ajout_en_liste([a(F,[Ad|Fin],LAd)|Liste],F,Ad,[a(F,Fin,LAd)|Liste]).

ajout_en_liste([X|Liste],F,Ad,[X|Liste1]):-
	ajout_en_liste(Liste,F,Ad,Liste1).




finir_liste([],[]).

finir_liste([a(F,[],LAd)|L],[a(F,LAd)|L1]):-
	finir_liste(L,L1).




gen_switch([],_,_,LSuiv,LSuiv).

    % si 1 seul elt avec 1 seule clause pas de switch - supprimer si besoin

gen_switch([a(_,[Ad])],_,Ad,LSuiv,LSuiv).

    % si 1 seul elt (avec 1 a n clauses) pas de switch - supprimer si besoin
/*
gen_switch([a(_,LAd)],_,Lab,LSuiv,TRTW):-
	gen_liste(LAd,Lab,LSuiv,TRTW).
*/
gen_switch(Liste,Ins,Lab,LSuiv,[label(Lab),SwtW|TRTW]):-
	cree_liste_switch(Liste,N,LSwt,LSuiv,TRTW),
	(g_read(mode_c,t) -> SwtW=..[Ins,Lab,N,LSwt]
                          ;  SwtW=..[Ins,N,LSwt]).




cree_liste_switch([],0,[],LSuiv,LSuiv).

cree_liste_switch([a(F,LAd)|Liste],N1,[(F,Lab)|LSwt],LSuiv,TRTW):-
	gen_liste(LAd,Lab,TRTW1,TRTW),
	cree_liste_switch(Liste,N,LSwt,LSuiv,TRTW1),
	N1 is N+1.




gen_liste([],_,LSuiv,LSuiv).

gen_liste([Ad],Ad,LSuiv,LSuiv).                  % 1 seule Cstj, Lst ou Stcj

gen_liste([Ad|LAd],Lab,LSuiv,RTW1):-             % de 2 a n
	RTW1=[label(Lab),try(Ad)|RTW],
	gen_liste1(LAd,LSuiv,RTW).


gen_liste1([Ad],LSuiv,[trust(Ad)|LSuiv]).

gen_liste1([Ad|LAd],LSuiv,RTW1):-
	RTW1=[retry(Ad)|RTW],
	gen_liste1(LAd,LSuiv,RTW).




gen_insts([cl(Ad,_,W)],Ad,[label(Ad)|W]).         % 1 seule inst.
	
gen_insts([cl(Ad,_,W)|LCl],Lab,LCl2W):-           % de 2 a n
	gen_insts1(LCl,Lab1,LClW),
	LCl2W=[label(Lab),try_me_else(Lab1),label(Ad),W|LClW].



gen_insts1([cl(Ad,_,W)],Lab,[label(Lab),trust_me_else_fail,label(Ad)|W]).

gen_insts1([cl(Ad,_,W)|LCl],Lab,LCl2W):-
	gen_insts1(LCl,Lab1,LClW),
	LCl2W=[label(Lab),retry_me_else(Lab1),label(Ad),W|LClW].




alloc_labels([],N,N).

alloc_labels([W1|W2],N,N2):-
	alloc_labels(W1,N,N1),                % pour listes imbriquees
	alloc_labels(W2,N1,N2).

alloc_labels(label(N),N,N1):-
	N1 is N+1.

alloc_labels(_,N,N).
