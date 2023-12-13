ukuranList([], 0).
ukuranList([_ | Tail], Result) :-
    ukuranList(Tail, Recursive),
    Result is Recursive + 1.

jumlahList([], 0).
jumlahList([Head | Tail], Result) :-
    jumlahList(Tail, Recursive),
    Result is Recursive + Head.

buangganjil([], []).
buangganjil([Head | Tail], Result) :-
    (Head mod 2 =:= 0 -> 
        buangganjil(Tail, Recursive),
        Result = [Head|Recursive]
    ;
        buangganjil(Tail, Result)).

buangnegatif([], []).
buangnegatif([Head | Tail], Result) :-
    (Head < 0 -> 
        buangnegatif(Tail, Result)
    ;
        buangnegatif(Tail, Recursive),
        Result = [Head|Recursive]).

predikat1(L) :- predikat2(L, L).
predikat2([], []).
predikat2([H | T], R) :-
    predikat2(T, T1),
    append(T1, [H], R).