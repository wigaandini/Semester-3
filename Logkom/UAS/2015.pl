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
/* NO 5
a) i. yes.
   ii. yes.
   iii. no.
   iv. no.
   v. yes
b) dia predikat2 tuh buat reverse listnya trus predikat 1 buat
   cek apakah listnya sama dengan list yang di reverse
*/


/* NO 6 
a) benar
b) salah, harusnya yang bikin aturan banyak tuh OR
c) salah, green buat efisiensi, red bisa ubah arti program
d) salah, dia harus ada knowledge base sama UI
e) salah, dia cuma handle backtrack, ya bisa dipake buat if else
   tapi bukan itu fungsi aslinya
*/