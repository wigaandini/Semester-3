enjoys(pete, X) :- big_kahuna_burger(X), !, fail.
enjoys(pete, X) :- burger(X).

burger(X) :- big_mac(X).
burger(X) :- big_kahuna_burger(X).
burger(X) :- whopper(X).

big_mac(a). 
big_mac(c).
big_kahuna_burger(b).
whopper(d). 



is_a_horse(Comet).
is_a_horse(Dasher).
is_a_horse(Prancer).
is_a_horse(Thunder).

is_parent_of(Comet, Dasher).
is_parent_of(Comet, Prancer).
is_parent_of(Dasher, Thunder).

is_fast(Prancer).
is_fast(Thunder).

valuable(X) :- is_a_horse(X), is_parent_of(Parent, Child), is_fast(Child).


/* NO 6
a) benar
b) salah, harusnya OR
c) salah, green buat efisiensi, red bisa ubah arti program
d) salah, yang bisa rekursif itu rule
e) salah, dia cuma handle backtrack, ya bisa dipake buat if else
   tapi bukan itu fungsi aslinya
*/