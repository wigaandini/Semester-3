main2:-
open('mahasiswa.txt',read,InStream),
readWord(InStream,W),
close(InStream),
write(W).
readWord(InStream,W):- get_code(InStream,Char), 
checkCharAndReadRest(Char,Chars,InStream), 
atom_codes(W,Chars).
checkCharAndReadRest(10,[],_):- !. 
/*return*/
checkCharAndReadRest(-1,[],_):- !. 
/*end_of_stream*/
checkCharAndReadRest(end_of_file,[],_):- !.
checkCharAndReadRest(Char,[Char|Chars],InStream):-
get_code(InStream,NextChar), 
checkCharAndReadRest(NextChar,Chars,InStream).