/*-------------------------------------------------------------------------*/
/* Passe 2: Mise en format interne.                                        */
/*                                                                         */
/* On profite de cette passe pour supprimer les true/0 en corps de clause. */
/*                                                                         */
/* predicat d'appel: format_interne(ClSrc,Arg1,T,C,NbChunk)                */
/*                                                                         */
/* entree                                                                  */
/* ClSrc  : clause source                                                  */
/*                                                                         */
/* sortie                                                                  */
/* Arg1   : 1er argument de la tete pour indexation ulterieure             */
/*          X  : (var libre) si variable ou si la tete n'a pas d'arguments */
/*          f/n: sinon                                                     */
/*          (Att: Arg1 n'a rien a voir avec les Argi ci-dessous)           */
/*                                                                         */
/* T      : format interne tete:  p(NoPred,Pred/N,[Arg,...],Trimming)      */
/*                                                                         */
/* C      : format interne corps:[p(NoPred,Pred/N,[Arg,...],Trimming),...] */
/*                                                                         */
/* NbChunk: nombre de Chunk dans le corps (pour determiner si allocate)    */
/*          un chunk est une suite de predicats inline suivie d'un predicat*/
/*          normal (pas inline) ou de la fin de la clause.                 */
/*                                                                         */
/*                                                                         */
/* Format interne d'un predicat: (I(t)=format interne de t)                */
/*                                                                         */
/* I(p(Arg1,...,ArgN))= p(NoPred,Pred/N,[I(Arg1),...,I(ArgN)],Trimming)    */
/*                                                                         */
/*     NoPred  : numero du predicat (No du Chunk auquel il appartient)     */
/*               la tete a pour numero 0, les chunk du corps sont numerotes*/
/*               a partir de 1 jusqu'a NbChunk.                            */
/*                                                                         */
/*     Pred/N  : le predicat et son arite                                  */
/*                                                                         */
/*     I(Argi) : format interne du ieme argument:                          */
/*                                                                         */
/*           I(X) =var(igv(Nom,NoPPOcc,NoPDOcc,Stc,Unsafe),PremOcc,DernOcc)*/
/*                 igv(...)  : infos generales de la variable,             */
/*                             commun a toutes les occurrences de X        */
/*                                                                         */
/*                    Nom    : y(No) si elle apparait dans plus d'un litt. */
/*                             (Passe 3 allouera No, ici libre)            */
/*                             libre sinon (peut etre une var perm ou temp)*/
/*                             (Passe 3 determinera si fausse perm ou temp)*/
/*                                                                         */
/*                    NoPPOcc: no du predicat contenant sa 1ere occurrence */
/*                                                                         */
/*                    NoPDOcc: no du predicat contenant sa dern occurrence */
/*                             (Passe 3 l'initialisera, ici libre)         */
/*                                                                         */
/*                    Stc    : 1ere occurrence en structure (t/f) ?        */
/*                                                                         */
/*                    Unsafe : est ce une var. dangereuse (t/f) ?          */
/*                             (Passe 2 et 3 le gereront)                  */
/*                                                                         */
/*                 PremOcc   : est-ce sa premiere occurrence (t/f) ?       */
/*                                                                         */
/*                 DernOcc   : est-ce sa derniere occurrence (t/f) ?       */
/*                             (Passe 3 l'initialisera, ici libre)         */
/*                                                                         */
/*           I(constante)    = cst(constante)                              */
/*           I(entier)       = int(entier)                                 */
/*           I([])           = nil                                         */
/*           I([Car|Cdr])    = lst(I(Car),I(Cdr))                          */
/*           I(f(A1,...,An)) = stc(f/n,[I(A1),...,I(An)])                  */
/*                                                                         */
/*     Trimming: nombre de variables permanentes necessaires apres ce      */
/*               predicat (pour trimming).                                 */
/*               Remarque: pour le predicat de tete ce nombre correspond   */
/*               exactement au nombre variables permanentes de toute la    */
/*               clause. Cette information est utilisee en mode c pour     */
/*               generer un allocate(N) en precisant la taille de depart   */
/*               l'environnement...   (Passe 3 l'initialisera, ici libre)  */
/*                                                                         */
/* Terminologie :                                                          */
/*                                                                         */
/* Les foncteurs d'arite 0 (les atomiques) se composent de :               */
/*   - les constantes      (ou atomes),                                    */
/*   - les entiers         (integer = entiers signes).                     */
/*-------------------------------------------------------------------------*/

:- public format_interne/5.

format_interne((T:-C),Arg1,T1,C1,NbChunk):-               % clause
	formate_tete(T,DicoVar,T1,Arg1),
	formate_corps(C,DicoVar,C1,NbChunk).

format_interne(T,Arg1,T1,[],0):-                          % fait
	formate_tete(T,_,T1,Arg1).




formate_tete(T,DicoVar,T1,Arg1):- 
	prem_arg(T,Arg1),                 % avant formate_pred pour ne pas 
	formate_pred(T,0,DicoVar,T1,_).   % lier Arg1 si var




prem_arg(T,F/N):-
	compound(T),
	arg(1,T,Arg),
	nonvar(Arg),
	functor(Arg,F,N).

prem_arg(_,_).                       % si pas d'arg alors 1er arg = var libre



formate_corps(C,DicoVar,C1,NbChunk):-
	formate_corps1(C,0,DicoVar,t,[],C1,NbChunk,_).


formate_corps1((P,Q),NoPred,DicoVar,DebChunk,LSuiv,P1,NoPred2,DebChunk2):-
	formate_corps1(P,NoPred,DicoVar,DebChunk,Q1,P1,NoPred1,DebChunk1),
	!,
	formate_corps1(Q,NoPred1,DicoVar,DebChunk1,LSuiv,Q1,NoPred2,DebChunk2),
	!.

formate_corps1(true,NoPred,_,DebChunk,LSuiv,LSuiv,NoPred,DebChunk).

formate_corps1(Pred,NoPred,DicoVar,DebChunk,LSuiv,[Pred1|LSuiv],
	       NoPred1,DebChunk1):-
	(DebChunk==t -> NoPred1 is NoPred+1
	             ;  NoPred1=NoPred),
	formate_pred(Pred,NoPred1,DicoVar,Pred1,InlinePred),
	(InlinePred==t -> DebChunk1=f
	               ;  DebChunk1=t).




formate_pred(Pred,NoPred,DicoVar,p(NoPred,F/N,LstArg1,_),InlinePred):-
	functor(Pred,F,N),
	Pred=..[_|LstArg],
	formate_lst_arg(LstArg,NoPred,DicoVar,f,LstArg1),
	(inline_predicate(F,N) -> InlinePred=t 
	                       ;  InlinePred=f).




formate_lst_arg([],_,_,_,[]).

formate_lst_arg([Arg|LstArg],NoPred,DicoVar,Stc,[Arg1|LstArg1]):-
	formate_arg(Arg,NoPred,DicoVar,Stc,Arg1),
	!,
	formate_lst_arg(LstArg,NoPred,DicoVar,Stc,LstArg1).




formate_arg(X,NoPred,DicoVar,Stc,var(IGV,PremOcc,_)):-
	var(X),
	lookup_var(DicoVar,v(X,IGV)),
	(var(IGV) -> IGV=igv(_,NoPred,_,Stc,_),
	             PremOcc=t
                  ;
                     IGV=igv(Nom,NoPPOcc,_,Stc1,Unsafe),
		     PremOcc=f,
                     detecte_var_Y(NoPPOcc,NoPred,Stc1,Nom,Unsafe)).

formate_arg([],_,_,_,nil).

formate_arg([Car|Cdr],NoPred,DicoVar,_,lst(Car1,Cdr1)):-
	formate_arg(Car,NoPred,DicoVar,t,Car1),
	formate_arg(Cdr,NoPred,DicoVar,t,Cdr1).

formate_arg(Fonc,NoPred,DicoVar,_,Fonc1):-
	functor(Fonc,F,N),
	(N=0 -> type_atomic(F,Fonc1)
	     ;  (Fonc=..[_|LstArg],
	         formate_lst_arg(LstArg,NoPred,DicoVar,t,LstArg1),
	         Fonc1=stc(F/N,LstArg1))).




lookup_var(DicoVar,V):-
	var(DicoVar),
	!,
	DicoVar=[V|_].

lookup_var([v(Y,IGV)|_],v(X,IGV)):-
	X==Y,
	!.

lookup_var([_|DicoVar],V):-
	lookup_var(DicoVar,V).




:- public type_atomic/2.

type_atomic(C,cst(C)):-
	atom(C),
	!.

type_atomic(N,int(N)):-
	integer(N),
	!.




detecte_var_Y(NoPred,NoPred,_,_,_).         % on ne peut rien dire

detecte_var_Y(0,1,_,_,_).                   % on ne peut rien dire

detecte_var_Y(NoPPOcc,_,Stc,y(_),Unsafe):-  % vraie permanente (cf passe 3)
	detecte_dangereuse(NoPPOcc,Stc,Unsafe).




detecte_dangereuse(NoPPOcc,Stc,t):-         % Y dangereuse si 1ere occ. 
	NoPPOcc\==0, Stc==f.            % ni en tete ni en structure

detecte_dangereuse(_,_,f).



	% Predicats inline : inline_predicate(Pred,Arite)
	% tous les predicats definis ici doivent avoir une clause
	% correspondante dans le predicat gen_inline_pred/5 en passe 4
	% decrivant quel code il faut leur generer

:- public inline_predicate/2.


inline_predicate(Pred,Arity):-
	g_read(no_inline,NoInline),
	inline_predicate(Pred,Arity,NoInline).





inline_predicate('$get_bc_reg',1,_).

inline_predicate('$cut',1,_).




inline_predicate('$dbg_true',0,_).




inline_predicate(pragma_c,1,_).

inline_predicate(calling_module_nb,1,_).        % must be an inline predicate




inline_predicate((=),2,f).




inline_predicate(var,1,f).

inline_predicate(nonvar,1,f).

inline_predicate(atom,1,f).

inline_predicate(integer,1,f).

inline_predicate(number,1,f).

inline_predicate(atomic,1,f).

inline_predicate(compound,1,f).

inline_predicate(callable,1,f).




inline_predicate(functor,3,f).

inline_predicate(arg,3,f).

inline_predicate(compare,3,f).

inline_predicate((=..),2,f).



inline_predicate((==),2,f).

inline_predicate((\==),2,f).

inline_predicate((@<),2,f).

inline_predicate((@=<),2,f).

inline_predicate((@>),2,f).

inline_predicate((@>=),2,f).




inline_predicate(is,2,f).

inline_predicate((=:=),2,f).

inline_predicate((=\=),2,f).

inline_predicate((<),2,f).

inline_predicate((=<),2,f).

inline_predicate((>),2,f).

inline_predicate((>=),2,f).




inline_predicate(g_assign,2,f).

inline_predicate(g_assignb,2,f).

inline_predicate(g_link,2,f).

inline_predicate(g_read,2,f).

inline_predicate(g_array_size,2,f).


