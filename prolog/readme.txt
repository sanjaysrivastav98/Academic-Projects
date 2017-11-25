

K S Sanjay Srivastav - 2015A7PS102P
Sree Teja Nanduri - 2015A7PS145P



ASSIGNMENT QUESTION 1:

Queries should be asked as below .


/*Examples given:*/
I/P:simplify((x*(y/y)-x)*x,Z).
O/P:Z=0.

I/P:simplify((a*b/1)*(c+1-c),Z).
O/P:Z=a*b.

I/P:simplify(((x+x)/x)*(y+y-y),Z).
O/P:Z = 2*y.

/*Other Examples*/

I/P:simplify(x+y+z,Z).
O/P:Z = a+b+c.

I/P:simplify(a+a+b,Z).
O/P: Z=2*a*b.

I/P:simplify(1+2+3,Z).
O/P:Z=6.

I/P:simplify(a*b+1*b,Z).
O/P:Z=(a+1)*b.

I/P:simplify(a-a+b,Z).
O/P:Z=b.

I/P:simplify(1*2*3*a*b,Z).
O/P:Z=6*a*b.

I/P:simplify(x/x+1+2+3,Z).
O/P:Z=7.

I/P:simplify(a*b+c*b+e*b,Z).
O/P:Z=(a+c+e)*b.

I/P:simplify(((a*b)/1)*(c-c+1),Z).
O/P:Z=a*b.








ASSIGNMENT QUESTION 2:


/*TESTCASE*/

This is a sample database added in the given code for verification 

student(k).
not(timeTableconflict(k)).
 not(dues(k)).
 not(noadvance(k)).
 not(gradeW(k)).
prereq(oop,[cse,python]).

highercourse(cse).
not(corecourse(cse,cs)).
not(clear(k,cse)).
prereq(cse,[c1,c2]).
clear(k,c1).
clear(k,c2).
single(k).
clear(k,y1).
clear(k,y2).
prereq(c2,[]).
prereq(c3,[]).
tobedone(cs,9,[c1,c2,c3,c4,c5,c6]).
sem(k,8).
 not(gA(k)).
 not(debarr(k)).
 not(gI(k)).
discipline(k,cs).
course(cse).
clear(k,python).
course(oop).
repeat(k,oop).

tobedone(cs,5,[c1,c2]).
tobedone(cs,6,[c1,c2,c3]).
clear(k,c3).
prereq(c1,[y1,y2]).
clear(k,c5).
clear(k,c4).
clear(k,c6).

Queries should be asked as follows:


/*In this question we are asking whether student k is eligible for undergoing the process of registration*/
Q1:reg(k,0).
Result:true.


/*In this question we are asking whether student k is eligible for undergoing the process of registration into PS1*/
Q2:regPS1(k).
Result:true.

/*This is a query whether a student k has cleared his courses y1 and y2*/
Q3:clearedcourses(k,[y1,y2]).
Result:true.

/*This is a query whether a student k can register to a course cse*/
Q4:regCourse(k,cse).
Result:true.

/*This is a query whether a student is eligible for doing his PS1*/
Q5:regPS1(k).
Result:true.

/*This is a query whether a student is eligible for doing his PS1*/
Q5:regPS2(k).
Result:true.

/*This is a query whether a student has to register into a semester other than PS*/
Q6:regsem(k).
Result:true.

/*This is a query whether a student is eligible for registering into an elective other than his/her discipline*/
Q7:regNonCore(k,cse).
Result:true.

/*This is a query whether a student is eligible to do a higher degree course of his/her own department*/
Q8:regHigher(k,python).
Result:true.


