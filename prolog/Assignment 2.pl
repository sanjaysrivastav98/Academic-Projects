/*FACTS */


/*This indicates X is the dean of department Y*/
dean(dARC,aRCD).
dean(dID,iD).

/*c is a course*/
course(c).
course(cse).
course(python).
course(oop).
course(c1).
course(c2).
course(c3).
course(y2).
course(y1).
clear(k,c5).
clear(k,c4).
clear(k,c6).


/*c is the core course of a paticular discipline d*/
corecourse(c,d).
corecourse(python,cs).
not(corecourse(cse,cs)).

/*c1 is a higher degree course*/
highercourse(c1).
highercourse(python).

/*This is a fact to be included in the knowledge base. It gives the list of all the prerequisites of the given course c*/
prereq(c,list).
prereq(oop,[cse,python]).
prereq(python,[]).
prereq(cse,[c1,c2]).
prereq(c1,[y1,y2]).
prereq(c2,[]).
prereq(c3,[]).
prereq(c4,[]).
prereq(c5,[]).
prereq(c6,[]).

/*This is a fact to be included in the knowledge base. It gives a list t of all the courses that a student of discipline d has to do before the semester z */
tobedone(d,z,t).
tobedone(cs,5,[c1,c2]).
tobedone(cs,6,[c1,c2,c3]).
tobedone(cs,8,[c1,c2,c3,c4]).
tobedone(cs,9,[c1,c2,c3,c4,c5,c6]).


/*Facts to be included in the knowledge base of a specific student say s*/

/*s is a student*/
student(s).	
student(k).

/*d is the first degree of a student s */
discipline(s,d).
discipline(k,cs).

/*If s1 is a dual degree student then dd is his second degree*/
dualdiscipline(s1,dd):-
	dual(s1).

/*z is the semester of student s*/
sem(s,z).
sem(k,8).


/*Student s is a single degree student */
single(s).
single(k).

/*Student s1 is a dual degree student */
dual(s1).

/*Student s has previous dues left*/
dues(s).
not(dues(k)).

/*Student s has not paid his advance fees */
noadvance(s).
not(noadvance(k)).

/*Student s has his grade card withheld*/
gradeW(s).
not(gradeW(k)).

/*Student s has his grade as Grade Awaiting*/
gA(s).
not(gA(k)).

/*Student s is debarred*/
debarr(s).
not(debarr(k)).

/*Student s has a grade I in his grade card*/
gI(s).
not(gI(k)).

/*Student s repeats a course c*/
repeat(s,c1).
repeat(k,oop).

/*Student s has got NC in a course c*/
nC(s,c2).

/*Student s has no timetable conflict*/
timeTableconflict(s).
not(timeTableconflict(k)).

/*Student s has previously registered for cource c*/
clear(s,c).
clear(k,python).
clear(k,c1).
clear(k,c2).
clear(k,c3).
clear(k,y1).
clear(k,y2).
not(clear(k,cse)).




/*RULES*/




/*This rule will display the output X meeting Y*/
meet(X,Y):-
	write('meet '),write(Y).

/*If a student X has to undergo the process of registration , he should abide by the following clauses of this rule and L signifies whether the student is under any late registration*/
reg(X,L):-
	((student(X),not(dues(X)),not(noadvance(X)),L is 0);
	((student(X),not(dues(X)),not(noadvance(X)),greater(7,L),L\=0)->meet(X,dARC));
	((student(X),not(dues(X)),not(noadvance(X)),L>7)->meet(X,dID));
	((student(X),dues(X),L=<7)->meet(X,dARC));
	((student(X),noadvance(X))->meet(X,dARC))),
	not(gradeW(X)),
	((gA(X))->meet(X,dARC);
	not(gA(X))),
	not(debarr(X)),
	not(gI(X)).


/*This is helper rule to check whether a student X has cleared the courses mentioned  in the list T*/
clearedcourses(X,[]).
clearedcourses(X,T):-
	student(X),[V|U]=T,clear(X,V),clearedcourses(X,U).

/*This is the process by which a student X can register in a course Y */
regCourse(X,Y):-
	student(X),course(Y),(not(clear(X,Y));(repeat(X,Y);(nC(X,Y)->meet(X,dARC);true))),
	prereq(Y,T),clearedcourses(X,T).


/*This is the process to be adopted for a student X to register in his or her PS I program*/
regPS1(X):-
	((student(X),not(dues(X)),not(noadvance(X)));
	((student(X),dues(X))->meet(X,dARC));
	((student(X),noadvance(X))->meet(X,dARC))),
	not(gradeW(X)),
	(gA(X)->meet(dARC);
	not(gA(X))),
	not(debarr(X)),
	not(gI(X)),
	sem(X,Z),
	discipline(X,D),
	tobedone(D,Z,T),clearedcourses(X,T).


/*This is the process to be adopted for a student X to register in his or her PS II program*/
regPS2(X):-
	((student(X),not(dues(X)),not(noadvance(X)));
	((student(X),dues(X))->meet(X,dARC));
	((student(X),noadvance(X))->meet(X,dARC))),
	not(gradeW(X)),
	(gA(X)->meet(X,dARC);
	not(gA(X))),
	not(debarr(X)),
	not(gI(X)),
	sem(X,Z),
	discipline(X,D),
	(single(X)->tobedone(D,9,T);
		tobedone(D,11,T)),clearedcourses(X,T).

/*It checks whether a student X has completed all the prerequisites of all the courses in the list L*/
clearedprereq(X,[]).
clearedprereq(X,L):-
	[H|T]=L,prereq(H,T1),clearedcourses(X,T1),clearedprereq(X,T).

/*This is the process to register in a particular semester, and checking if a student hasn't got utmost 2 NC's previously*/
regsem(X):-
	not(timeTableconflict(X)),
	reg(X,0),
	sem(X,Z),
	discipline(X,D),
	succ(Z,P),
	(tobedone(D,Z,T),clearedcourses(X,T)),
	tobedone(D,P,T1),clearedprereq(X,T1),
	twonC(X,0,T).

/*This is a rule to check thoses cases where a student has atmost two notcleared courses in his previous semesters i.e in the list T*/
twonC(X,Y,[]).
twonC(X,A,T):-
	student(X),[V|U]=T,
	((nC(X,V),A is 0)->(twonC(X,1,U));
	(nC(X,V),A is 1)->(twonC(X,2,U));
	(nC(X,V),A is 2)->A\=2;
	twonC(X,A,U)).
	
			
/*This is a rule for the requirements a student to do the course Y which is an elective out of his discipline and out of the humanitive electives category*/
regNonCore(X,Y):-
	not(timeTableconflict(X)),
	student(X),discipline(X,U),course(Y),not(corecourse(Y,U)),(not(clear(X,Y));(repeat(X,Y);(nC(X,Y)->meet(X,dARC);true))),
	prereq(Y,T1),clearedcourses(X,T1),sem(X,Z),tobedone(U,Z,T),clearedcourses(X,T).





/*This is a rule to check for two variables and their relation*/
greater(X,Y):-
	X>=Y.


/*This is a rule for a student X to do higher degree course Y */
regHigher(X,Y):-
	not(timeTableconflict(X)),discipline(X,U),corecourse(Y,U),
	sem(X,Z),
	student(X),course(Y),highercourse(Y),corecourse(Y,U),(not(clear(X,Y));(repeat(X,Y);(nC(X,Y)->meet(X,dARC);true))),
	prereq(Y,T1),clearedcourses(X,T1),
	((single(X),greater(Z,5),tobedone(U,5,T))->clearedcourses(X,T);
	(dual(X),greater(Z,7),tobedone(U,5,T),dualdiscipline(X,W),tobedone(W,7,T2))->(clearedcourses(X,T),clearedcourses(X,T2));false).





