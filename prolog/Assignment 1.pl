
add(X,0,X).
add(0,X,X).

add(A*X,X,Z):-
	simplify(A*X+1*X,Z).
add(X,A*X,Z):-
	simplify(1*X+A*X,Z).

add(B*X,B*Y,Z):-
	simplify(B*(X+Y),Z).
add(X*B,Y*B,Z):-
	simplify(B*(X+Y),Z).
add(B*X,Y*B,Z):-
	simplify(B*(X+Y),Z).
add(X*B,Y*B,Z):-
	simplify(B*(X+Y),Z).

simplify((B*X)+(B*Y),Z):-
	simplify(B*(X+Y),Z).
simplify((X*B)+(Y*B),Z):-
	simplify(B*(X+Y),Z).
simplify((B*X)+(Y*B),Z):-
	simplify(B*(X+Y),Z).
simplify((X*B)+(Y*B),Z):-
	simplify(B*(X+Y),Z).
simplify(X+Y-X,Z):-
	simplify(Y+0,Z).
add(X,Y,Z):-
	Y\=0,X\=0,(number(X),number(Y))->Z is X+Y;
	Z=X+Y.
simplify(X+X,Z):-
	simplify(2*X,Z).
sub(X,0,X).
sub(0,X,Z):-
	mult(-1,X,Z).

sub(A*X,X,Z):-
	simplify(A*X-1*X,Z).
sub(X,A*X,Z):-
	simplify(1*X-A*X,Z).

sub(X,X,0).

sub(B*X,B*Y,Z):-
	simplify(B*(X-Y),Z).
sub(X*B,Y*B,Z):-
	simplify(B*(X-Y),Z).
sub(B*X,Y*B,Z):-
	simplify(B*(X-Y),Z).
sub(X*B,Y*B,Z):-
	simplify(B*(X-Y),Z).

simplify((B*X)-(B*Y),Z):-
	simplify(B*(X-Y),Z).
simplify((X*B)-(Y*B),Z):-
	simplify(B*(X-Y),Z).
simplify((B*X)-(Y*B),Z):-
	simplify(B*(X-Y),Z).
simplify((X*B)-(Y*B),Z):-
	simplify(B*(X-Y),Z).
sub(X,Y,Z):-
	X\=0,Y\=0,(number(X),number(Y))->Z is X-Y;
	Z=X-Y.

mult(X,1,X).
mult(1,X,X).
mult(X,0,0).
mult(0,X,0).
mult(X,Y,Z):-
	(X\=1,X\=0,Y\=1,Y\=0,(number(X),number(Y))->Z is X*Y);
	Z=X*Y.


simplify(X*Y+Z*Y,W):-
	((atom(X);number(X)),(number(Y);atom(Y)))->(add(X,Z,Z1),mult(Z1,Y,W));
	(simplify(X+Z,Z1),simplify(Z1*Y,Z)).

simplify(X*Y-Z*Y,W):-
	((atom(X);number(X)),(number(Y);atom(Y)))->(sub(X,Z,Z1),mult(Z1,Y,W));
	(simplify(X-Z,Z1),simplify(Z1*Y,Z)).



div(X,X,1).
div(X,1,X).
div(0,X,0).

div(A*X,X,Z):-
	simplify(A*X/X,Z).
div(X,A*X,Z):-
	simplify(X/(A*X),Z).
div(B*X,B*Y,Z):-
	simplify(X/Y,Z).
div(X*B,Y*B,Z):-
	simplify(X/Y,Z).
div(B*X,Y*B,Z):-
	simplify(X/Y,Z).
div(X*B,Y*B,Z):-
	simplify(X/Y,Z).

simplify(B*X/(B*Y),Z):-
	simplify(X/Y,Z).
simplify(X*B/(Y*B),Z):-
	simplify(X/Y,Z).
simplify(B*X/Y*B,Z):-
	simplify(X/Y,Z).
simplify(X*B/Y*B,Z):-
	simplify(X/Y,Z).

div(X,Y,Z):-
	(number(X),number(Y))->Z is X/Y;
	Z=X/Y.

simplify(X/(A*X),Z):-
	simplify(1/A,Z).
simplify(A*X/X,Z):-
	simplify(A/1,Z).


simplify(X/Y,Z):-
	((atom(X);number(X)),(number(Y);atom(Y)))->div(X,Y,Z);
	((atom(Y);number(Y))->(simplify(X,Z1),div(Z1,Y,Z)));
	((atom(X);number(X))->(simplify(Y,Z1),div(X,Z1,Z)));
	(simplify(X,Z3),simplify(Y,Z4),div(Z3,Z4,Z)).

simplify(X*Y,Z):-
	((atom(X);number(X)),(number(Y);atom(Y)))->mult(X,Y,Z);
	((atom(Y);number(Y))->(simplify(X,Z1),mult(Z1,Y,Z)));
	((atom(X);number(X))->(simplify(Y,Z1),mult(Z1,X,Z)));
	(simplify(X,Z3),simplify(Y,Z4),mult(Z3,Z4,Z)).

simplify(X+Y,Z):-
	((atom(X);number(X)),(number(Y);atom(Y)))->add(X,Y,Z);
	((atom(Y);number(Y))->(simplify(X,Z1),add(Z1,Y,Z)));
	((atom(X);number(X))->(simplify(Y,Z1),add(Z1,X,Z)));
	(simplify(X,Z3),simplify(Y,Z4),add(Z3,Z4,Z)).

simplify(X-Y,Z):-
	((atom(X);number(X)),(number(Y);atom(Y)))->sub(X,Y,Z);
	((atom(Y);number(Y))->(simplify(X,Z1),sub(Z1,Y,Z)));
	((atom(X);number(X))->(simplify(Y,Z1),sub(Z1,X,Z)));
	(simplify(X,Z3),simplify(Y,Z4),sub(Z3,Z4,Z)).	

	

simplify(X,Z):-
	(atom(X)->Z =X;
	number(X)->Z is X;
	true).


