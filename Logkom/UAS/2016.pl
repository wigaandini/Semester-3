main :-
    open('mahasiswa.txt', read, Str),
    read_file(Str,Lines),
    close(Str),
    write(Lines), nl.

read_file(Stream,[]) :-
    at_end_of_stream(Stream).

read_file(Stream,[X|L]) :-  
    \+ at_end_of_stream(Stream),
    read(Stream,X),
    read_file(Stream,L).


parent(charles, william).
parent(charles, harry).
parent(phillips, charles).
parent(elizabeth, charles).
parent(victoria, elizabeth).
ancestor(X,Y) :- parent(X,Y). 
ancestor(X,Y) :- ancestor(X,Z), !, parent(Z,Y).


number_of_parents(adam, 0) :- !.
number_of_parents(hawa, 0) :- !.
number_of_parents(X, 2).


male(arif).
male(pandu).
female(dyah).
female(arini).
parents(pandu, arif, dyah).
parents(arini, arif, dyah).
sister_of(X,Y) :- 
    female(X), parents(X, A, B), parents(Y, A, B), X \== Y.