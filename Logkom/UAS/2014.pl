/* NO 5
a) salah
b) benar
c) benar
d) salah, H harusnya a bukan [a]
e) salah, dia cuma ngecut backtrack, ga mesti di if else doang */


myreversedlist([], []).
myreversedlist([H | T], R) :-
    myreversedlist(T, T1),
    append(T1, [H], R).

buangpositif([], []).
buangpositif([Head | Tail], [Head | Result]) :-
    Head =< 0,
    buangpositif(Tail, Result).
buangpositif([Head | Tail], Result) :-
    buangpositif(Tail, Result).