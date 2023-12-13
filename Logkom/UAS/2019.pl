% Predikat isMember untuk mengecek apakah X adalah anggota dari sebuah list
isMember(X, [X | _]) :- !.
isMember(X, [_ | Tail]) :-
    isMember(X, Tail).

% Predikat intersectList untuk mencari elemen-elemen yang beririsan antara dua list
intersectList([], _, []).
intersectList([Head | Tail], L2, Result) :-
    (isMember(Head, L2) -> intersectList(Tail, L2, RecursiveResult), Result = [Head | RecursiveResult];
    intersectList(Tail, L2, Result)).



classify(0, zero) :- !.
classify(X, negative) :-
    X < 0, !.
classify(X, positive) :- !.
go :- 
    repeat, write('Masukkan angka: '), read(X), 
    classify(X, Result), Result = positive, write('Nilai positif adalah '), write(X), nl.