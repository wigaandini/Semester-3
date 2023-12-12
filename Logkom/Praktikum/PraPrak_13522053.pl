/* Nama : Erdianti Wiga Putri Andini */
/* NIM : 13522053 */
/* Kelas : K-01 */

/* ******************************************************************** */
                /* BAGIAN I : Fakta, Rule, dan Query */
/* ******************************************************************** */

/* Deklarasi Fakta */
/* pria(X) : X adalah pria */
pria(athif).
pria(dillon).
pria(henri).
pria(michael).
pria(hanif).
pria(robert).
pria(bagas).
pria(fio).
pria(daniel).
pria(rupert).

/* wanita(X) : X adalah wanita */
wanita(joli).
wanita(elysia).
wanita(margot).
wanita(jena).
wanita(jeni).
wanita(ana).
wanita(emma).

/* usia(X,Y) : X berusia Y */
usia(athif, 60).
usia(dillon, 63).
usia(henri, 48).
usia(michael, 28).
usia(hanif, 47).
usia(robert, 32).
usia(bagas, 29).
usia(fio, 30).
usia(daniel, 7).
usia(rupert, 6).
usia(joli, 58).
usia(elysia, 500).
usia(margot, 43).
usia(jena, 27).
usia(jeni, 28).
usia(ana, 23).
usia(emma, 6).

/* menikah(X,Y) : X menikah dengan Y */
menikah(athif, joli).
menikah(joli, athif).
menikah(dillon, elysia).
menikah(elysia, dillon).
menikah(henri, margot).
menikah(margot, henri).
menikah(fio, jena).
menikah(jena, fio).
menikah(fio, jeni).
menikah(jeni, fio).

/* anak(X,Y) : X adalah anak Y */
anak(margot, athif).
anak(margot, joli).
anak(michael, athif).
anak(michael, joli).
anak(hanif, dillon).
anak(hanif, elysia).
anak(robert, henri).
anak(robert, margot).
anak(bagas, henri).
anak(bagas, margot).
anak(jena, henri).
anak(jena, margot).
anak(jeni, hanif).
anak(ana, hanif).
anak(emma, jeni).
anak(emma, fio).
anak(daniel, fio).
anak(daniel, jena).
anak(rupert, fio).
anak(rupert, jena).


/* Deklarasi Rules */
/* saudara(X,Y) : X adalah saudara kandung maupun tiri dari Y */
saudara(X,Y) :-
    anak(X,V),
    anak(Y,V),
    X \== Y.

/* saudaratiri(X,Y) : X adalah saudara tiri dari Y */
saudaratiri(X,Y) :-
    saudara(X,Y),
    anak(X,A), 
    anak(Y,A),
    anak(X,V),
    anak(Y,Z),
    menikah(A,V), 
    menikah(A,Z),
    V \== Z.

/* kakak(X,Y) : X adalah kakak dari Y (kakak kandung maupun tiri) */
kakak(X,Y) :- 
    saudara(X,Y),
    usia(X,U),
    usia(Y,V),
    U > V.

/* keponakan(X,Y) : X adalah keponakan dari Y */
keponakan(X,Y) :- 
    anak(X,U),
    saudara(U,Y).

/* mertua(X,Y) : X adalah mertua dari Y */
mertua(X,Y) :-
    menikah(Y,U),
    anak(U,X).

/* nenek(X,Y) : X adalah nenek dari Y */
nenek(X,Y) :-
    wanita(X),
    anak(U,X),
    anak(Y,U).

/* keturunan(X,Y) : X adalah keturunan  dari Y (anak, cucu, dan seterusnya) */
keturunan(X,Y) :- anak(X,Y).
keturunan(X,Y) :- nenek(Y,X).
keturunan(X,Y) :- anak(X,U), keturunan(U,Y).

/* lajang(X) : X adalah orang yang tidak menikah */
lajang(X) :- pria(X), \+ menikah(X,_).
lajang(X) :- wanita(X), \+ menikah(X,_).

/* anakbungsu(X) : X adalah anak paling muda */
anakbungsu(X) :-
    anak(X,V),
    pria(V),
    \+ kakak(X,_).

/* yatimpiatu(X) : X adalah orang yang orang tuanya tidak terdefinisi */
yatimpiatu(X) :- pria(X), \+ anak(X,_).
yatimpiatu(X) :- wanita(X), \+ anak(X,_).



/* ******************************************************************** */
                    /* BAGIAN II : Rekursivitas */
/* ******************************************************************** */

/* 1. Exponent
A (Nilai A > 0) merupakan basis perpangkatan, 
sedangkan B merupakan pangkat dari A (Nilai B ≥ 0). 
exponent(A, B, X) akan mengeluarkan hasil perpangkatan AB yaitu X. */
/* main3 :- exponent(2,3,X), write(X). */
exponent(_,0,1) :- !.
exponent(A,B,X) :-
    B1 is B-1, 
    exponent(A,B1,X1), 
    X is A*X1.

/* 2. Population
Walikota Los Bandung ingin mengetahui pertumbuhan populasi di kotanya dalam T tahun (Nilai  T ≥ 0). 
Pada awalnya (tahun ke-0), kota Los Bandung memiliki populasi awal P (Nilai P > 0). 
Pada setiap tahunnya, populasi kota Los Bandung akan bertambah banyak dengan rasio R (Nilai R > 1). 
Suatu nilai C (Nilai C ≥ 0 dan < P) merupakan nilai khusus yang menggambarkan dinamika penduduk kota awal. 
Nilai C akan bertambah sebesar 1 setiap tahunnya. 
Pada tahun ganjil,  jumlah penduduk (setelah bertambah dengan rasio R) akan bertambah sebanyak C. 
Sementara pada tahun genap, jumlah penduduk berkurang sebanyak C. 
population(P, R, T, C, X) akan menghasilkan jumlah penduduk pada tahun T, yaitu X. */
/* main2 :- population(3,2,5,0,Y), write(Y). */
population(P, _, 0, _, P) :- !.
population(P, R, T, C, X) :-
    T > 0,
    T1 is T - 1,
    C1 is C + 1,
    (T mod 2 =:= 0 -> 
        P1 is P * R - C1,
        population(P1, R, T1, C1, X)
    ;
        P1 is P * R + C1,
        population(P1, R, T1, C1, X)).

/* 3. Perrin 
Perrin sequence merupakan suatu barisan angka sebagai berikut:
3, 0, 2, 3, 2, 5, 5, 7, 10, 12, 17, 22, 29, 39, 51, 68, ...
Perrin sequence sering kali disebut sebagai “skipponaci”, dimana suku ke-3 dihasilkan dari penjumlahan suku ke-1 dan ke-0, dan seterusnya. 
perrin(N, X) akan mengembalikan nilai dari suku ke-N pada Perrin sequence, yaitu X. Nilai N dimulai dari 0 */
/* main3 :- perrin(11,X), write(X). */
perrin(0,3) :- !.
perrin(1,0) :- !.
perrin(2,2) :- !.
perrin(N,X) :-
    N > 2,
    N1 is N-2,
    perrin(N1,X1),
    N2 is N1-1,
    perrin(N2,X2),
    X is X1 + X2.

/* 4. HCF
hcf(A, B, X) akan mengeluarkan hasil X yaitu highest common factor dari A dan B. */
/* main3 :- hcf(48,18,X), write(X). */
hcf(A,B,X) :-
    A = B,
    X is A.
hcf(A,B,X) :-
    A > B,
    A1 is A-B,
    hcf(A1,B,X).
hcf(A,B,X) :-
    B > A,
    B1 is B-A,
    hcf(A,B1,X).

/* 5. Make Pattern 
makePattern(N) akan menuliskan sebuah persegi angka sebesar N satuan 
dengan setiap angkanya menyatakan kedalaman persegi. */
makePattern(N) :-
    RowAtas is (N + 1) // 2, 
    RowBawah is N // 2, 
    writeAtas(N, 0, RowAtas, N),
    writeBawah(N, 0, RowBawah, N).

writeLoop(0, _Char) :- !.
writeLoop(N, Char) :-
    N > 0,
    write(Char),
    N1 is N - 1,
    writeLoop(N1, Char).

writeKiri(0).
writeKiri(Nfill) :-
    Nfill > 0,
    N1 is Nfill - 1,
    writeKiri(N1),
    write(N1).

writeKanan(0).
writeKanan(Nfill) :-
    Nfill > 0,
    N1 is Nfill - 1,
    write(N1),
    writeKanan(N1).

writeAtas(_N, _Char, 0, _Constant) :- !. 
writeAtas(_N, _Char, I, _Constant) :-
    I > 0,
    Nfill is (_Constant - _N) // 2, 
    writeKiri(Nfill),
    writeLoop(_N, _Char),
    writeKanan(Nfill), nl,
    C1 is _Char + 1, 
    I1 is I - 1, 
    N1 is _N - 2, 
    writeAtas(N1, C1, I1, _Constant).

writeBawah(_N, _Char, 0, _Constant) :- !. 
writeBawah(_N, _Char, I, _Constant) :-
    I > 0,
    Nfill is (_Constant - _N) // 2, 
    C1 is _Char + 1,
    I1 is I - 1, 
    N1 is _N - 2, 
    writeBawah(N1, C1, I1, _Constant),
    writeKiri(Nfill),
    writeLoop(_N, _Char),
    writeKanan(Nfill), nl.



/* ******************************************************************** */
                    /* BAGIAN III : List */
/* ******************************************************************** */

/* 1. List Statistic */
/* a. min(List,Min) : mencari elemen dengan nilai minimum */
min([Head],Head).
min([Head|Tail],Head) :-
    min(Tail,Y),
    Head =< Y.
min([Head|Tail],Y) :-
    min(Tail,Y),
    Head > Y.

/* b. max(List,Max) : mencari elemen dengan nilai maksimum */
max([Head],Head).
max([Head|Tail],Head) :-
    max(Tail,Y),
    Head >= Y.
max([Head|Tail],Y) :-
    max(Tail,Y),
    Head < Y.

/* c. range(List,Range) : mencari selisih antara elemen terbesar dan elemen terkecil */
range([Head|Tail],R) :-
    max([Head|Tail],U),
    min([Head|Tail],V),
    R is U - V.

/* d. count(List,Count) : mencari jumlah elemen pada list */
count([], 0).
count([_|Tail], C) :-
    count(Tail, C1),
    C is C1 + 1.

/* e. sum(List,Sum) : mencari jumlah total elemen pada list */
sum([], 0).
sum([Head|Tail], S) :-
    sum(Tail, S1),
    S is S1 + Head.


/* 2. List Manipulation */
/* a. Get Index 
Mengembalikan indeks sebuah elemen pada list. 
Jika ada dua elemen yang bernilai sama pada list, maka yang dikembalikan adalah yang pertama. 
Jika elemen tidak ditemukan pada list, kembalikan 'no' Index dimulai dari 1. */
getIndex([Head|_],Head,1).
getIndex([_|Tail],Searched,Idx) :-
    getIndex(Tail,Searched,Idx1),
    Idx is Idx1 + 1.


/* b. Get Element
Mengembalikan sebuah elemen pada list yang ditunjuk pada indeks. 
Jika indeks tidak valid, kembalikan 'no'. Index dimulai dari 1. */
getElement([Head|_],1,Head).
getElement([_|Tail],Idx,Searched) :-
    getElement(Tail,Idx1,Searched),
    Idx is Idx1 + 1.


/* c. Swap
Menukar dua buah elemen pada indeks tertentu dan mengembalikan List yang sudah diperbarui nilainya. 
Index dimulai dari 1. Jika indeks tidak valid, kembalikan 'no'. */
replace([OldEl|Tail],[NewEl|Tail],Idx,OldEl,NewEl) :-
    Idx == 0, !.

replace([First|Tail],[First|NewTail],Idx,OldEl,NewEl) :- 
    Idx > 0,
    NewIdx is Idx - 1, 
    replace(Tail,NewTail,NewIdx,OldEl,NewEl).

swap(OldList, I, J, NewList) :-
    A is I - 1,
    B is J - 1,
    replace(OldList, List, A, X, Y),
    replace(List, NewList, B, Y, X).


/* d. Slice
Membuat list baru yang elemennya merupakan elemen List ke-Start hingga elemen List ke-End-1. 
Index dimulai dari 1. */
slice(List, Start, End, Result) :-
    startSlice(List, 1, Start, End, Result).

/* cari sampe kosongin list, kalau list kosong bakal return kosong */
startSlice([], _, _, _, []).

/* insert current element kalau idx sesuai */
startSlice([Head|Tail], Idx, Start, End, [Head|Result]) :-
    Idx >= Start,
    Idx < End,
    Idx1 is Idx + 1,
    startSlice(Tail, Idx1, Start, End, Result).

/* stop rekursif saat idx >= end, elmt end ga keinclude */
startSlice(_, Idx, _, End, []) :- 
    Idx >= End.

/* skip elemen sebelum start */
startSlice([_|Tail], Idx, Start, End, Result) :-
    Idx < Start,
    Idx1 is Idx + 1,
    startSlice(Tail, Idx1, Start, End, Result).


/* e. Sort List
Membuat list baru yang merupakan hasil pengurutan dari List awal. 
(Hint: gunakan fungsi swap yang sudah dibuat) */
sortList([Head],[Head]) :- !.
sortList([Head|Tail], [Head1|Tail1]) :-
    min([Head|Tail], Min),
    getIndex([Head|Tail], Min, IdxMin),
    IdxMin \== 1,
    swap([Head|Tail], 1, IdxMin, [Head1|Tail2]),
    sortList(Tail2, Tail1).
sortList([Head|Tail], [Head|Tail1]) :-
    min([Head|Tail], Min),
    Head == Min,
    sortList(Tail,Tail1).

/* ******************************************************************** */
                            /* BONUS */
/* ******************************************************************** */
/* Buatlah program permainan menebak angka sederhana dengan mendefinisikan perintah* dan query berikut:
start: Memulai permainan. Program menghasilkan nilai secret number serta menginisiasi skor pemain.
guess(X): menebak X sebagai nilai secret number. Program akan merespon apakah X terlalu besar, terlalu kecil, atau sama dengan secret number. Program juga akan mengurangi skor jika tebakan pemain salah dan menambah skor jika tebakan pemain benar.
reset: Mereset dan menghasilkan nilai secret number baru serta menginisiasi kembali skor pemain.
exit: Keluar dari permainan.

Catatan:
Jika permainan belum berlangsung atau sudah selesai, kemudian perintah selain start dimasukkan, kembalikan false (atau no).
Pastikan secret number dihasilkan secara random.
Program ini memerlukan fungsi bawaan print, random, dan teknik dynamic predicate. Selamat melakukan eksplorasi.
Diperbolehkan menggunakan fungsi I/O untuk merapikan dan memperindah output.
Sangat disarankan mengerjakan bonus karena akan sangat berguna di tubes🥰😘

*) Perintah adalah fungsi yang tidak memiliki parameter apapun. */
/* :- use_module(library(random)). */
:- dynamic(secret_number/1).
:- dynamic(score/1).
:- dynamic(cont/1).
:- dynamic(correct/1).

randomNumber :-
    random(1, 100, RandomNum),
    asserta(secret_number(RandomNum)),
    asserta(score(0)),
    asserta(cont(true)),
    asserta(correct(fail)).

start :-
    write('Welcome to Number Guesser Prolog!'), nl,
    write('Guess a Number between 1 to 100.'), nl,
    randomNumber,
    write('Score: '), score(X), write(X), nl, !.

guess(X) :-
    cont(Y),
    Y == true,
    secret_number(Secret),
    X =:= Secret,
    write('Correct.'), nl,
    asserta(correct(true)),
    retract(score(CurrentScore)),
    NewScore is CurrentScore + 10,
    asserta(score(NewScore)),
    write('Score: '), score(NewScore), write(NewScore), nl, !.

guess(X) :-
    cont(Y),
    Y == true,
    secret_number(Secret),
    X > Secret,
    write('Too Large.'), nl,
    asserta(correct(fail)),
    retract(score(CurrentScore)),
    NewScore is CurrentScore - 1,
    asserta(score(NewScore)),
    write('Score: '), score(NewScore), write(NewScore), nl, !.

guess(X) :-
    cont(Y),
    Y == true,
    secret_number(Secret),
    X < Secret,
    write('Too Small.'), nl,
    asserta(correct(fail)),
    retract(score(CurrentScore)),
    NewScore is CurrentScore - 1,
    asserta(score(NewScore)),
    write('Score: '), score(NewScore), write(NewScore), nl, !.

reset :-
    secret_number(Secret),
    write('Secret Number is '), write(Secret), nl,
    write('Score: '), score(X), write(X), nl,
    retract(secret_number(_)),
    retract(score(_)),
    retract(cont(_)),
    retract(correct(_)),
    write('resetting the game..'), nl, nl,
    start, !.

exit :-
    retract(secret_number(_)),
    retract(score(_)),
    retract(cont(_)),
    retract(correct(_)),
    write('Thankyou for Playing!'), nl, !.