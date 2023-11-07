main :-
number_of_parents(hawa, 2).

number_of_parents(adam, N) :- !, N = 0.
number_of_parents(hawa, N) :- !, N = 0.
number_of_parents(X, 2).
# |?- Y is number_of_parents(john, Y).