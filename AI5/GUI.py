#2015A7PS0102P K S Sanjay Srivastav
from turtle import *
import turtle

def draw_box(t,name,xcor,ycor,flag,flag1):
	t.pu()
	t.speed(0)
	t.goto(xcor,ycor)
	t.pensize(0)
	t.pd()
	t.color('grey')
	t.goto(xcor+50,ycor)
	t.pensize(3)
	t.goto(xcor+50,ycor-28)
	t.goto(xcor,ycor-28)
	t.pensize(0)
	t.goto(xcor,ycor)
	t.pu()
	if flag1==1:
		t.goto(xcor+.4,ycor-.4)
		t.color('white','light green')
		t.fill(True)
		t.pd()
		t.goto(xcor+49,ycor-.4)
		t.goto(xcor+49,ycor-26)
		t.goto(xcor+.4,ycor-26)
		t.goto(xcor+.4,ycor-.4)
		t.fill(False)
		t.pu()
	else:
		t.goto(xcor,ycor)
		t.color('white','yellow')
		t.fill(True)
		t.pd()
		t.goto(xcor+50,ycor)
		t.goto(xcor+50,ycor-28)
		t.goto(xcor,ycor-28)
		t.goto(xcor,ycor)
		t.fill(False)
		t.pu()
	t.pensize(1)
	t.color('black')
	if flag==1:
		t.goto(xcor+28,ycor-21)
		t.write(name,True,align="center",font=("Arial", 12,"bold"))
	else:
		t.goto(xcor+10,ycor-12)
		t.pd()
		t.goto(xcor+20,ycor-12)
		t.goto(xcor+20,ycor-18)
		t.pu()
		t.goto(xcor+28,ycor-21)
		t.write(name,True,align="center",font=("Arial", 12,"bold"))

def drawOutline(t):
	t.pu()
	t.goto(-440,342)
	t.pd()
	t.goto(440,342)
	t.goto(440,-342)
	t.goto(-440,-342)
	t.goto(-440,342)
	t.pu()
	t.goto(-320,335)
	t.color('grey','light blue')
	t.fill(True)
	t.pd()
	t.goto(-320,310)
	t.pensize(3)
	t.goto(-190,310)
	t.goto(-190,335)
	t.pensize(0)
	t.goto(-320,335)
	t.fill(False)
	t.pu()
	t.goto(-315,315)
	t.color('black')
	t.write("Query variables",True,align="left",font=("Arial", 12,"bold"))
	t.goto(-320,335)
	t.color('grey','light blue')
	t.fill(True)
	t.goto(90,335)
	t.pd()
	t.goto(250,335)
	t.pensize(3)
	t.goto(250,310)
	t.goto(90,310)
	t.pensize(0)
	t.goto(90,335)
	t.fill(False)
	t.pu()
	t.goto(100,315)
	t.color('black')
	t.write("Condition variables",True,align="left",font=("Arial", 12,"bold"))

def clearUI(t):
	t.pu()
	t.pensize(1)
	t.color('black','white')
	t.fill(True)
	t.goto(-441,343)
	t.pd()
	t.goto(441,343)
	t.goto(441,-341)
	t.goto(-441,-341)
	t.goto(-441,343)
	t.fill(False)


def processing(t,flag):
	t.pu()
	if flag==0:
		t.goto(230,-230)
		t.pensize(3)
		t.color('pink','white')
		t.fill(True)
		t.pd()
		t.goto(330,-230)
		t.goto(330,-260)
		t.goto(230,-260)
		t.goto(230,-230)
		t.fill(False)
		t.pu()
		t.goto(235,-255)
		t.color('red')
		t.write('New Query',True,align="left",font=("Arial", 12,"bold"))

	t.pensize(3)
	t.color('pink','white')
	t.goto(220,-270)
	t.fill(True)
	t.pd()
	t.goto(380,-270)
	t.goto(380,-305)
	t.goto(220,-305)
	t.goto(220,-270)
	t.fill(False)
	t.pu()
	t.pensize(1)
	t.goto(225,-300)
	t.color('red')
	if flag==1:
		t.write('Click to process the query',True,align="left",font=("Arial", 8,"bold"))
	else:
		t.write('Processing is going on',True,align="left",font=("Arial", 8,"bold"))
		

def drawBottom(t):
	global countGUI,countGUI1
	t.pu()
	t.goto(-300,-275)
	t.color('grey','light green')
	t.fill(True)
	t.pd()
	t.goto(200,-275)
	t.pensize(3)
	t.goto(200,-305)
	t.goto(-300,-305)
	t.pensize(0)
	t.goto(-300,-275)
	t.fill(False)
	t.pu()
	t.goto(-300,-310)
	t.fill(True)
	t.pd()
	t.goto(200,-310)
	t.pensize(2)
	t.goto(200,-339)
	t.goto(-300,-339)
	t.pensize(0)
	t.goto(-300,-310)
	t.fill(False)
	t.pu()
	processing(t,1)
	countGUI=0
	countGUI1=0
	

def close_main_window():
	turtle.mainloop()

def getCornerCoors(x,y,length):
	ycor=300
	for i in range(length):
		if y<=ycor-i*(33) and y>=ycor-(i+1)*(33)+5:
			if x>=-300 and x<=-250:
				return -300,ycor-i*(33),i
			elif x>=-240 and x<=-190:
				return -240,ycor-i*(33),i
			elif x>=100 and x<=150:
				return 100,ycor-i*(33),i
			elif x>=160 and x<=210:
				return 160,ycor-i*(33),i
	return False,False,-1


def write_exp(exp):
	t=Turtle()
	t.pu()
	t.ht()
	t.speed(0)
	t.goto(-295,-300)
	t.write("Generated query "+str(exp),True,align="left",font=("Arial", 12,"bold"))
	t.goto(-295,-335)
	t.write("Answer   ",True,align="left",font=("Arial", 12,"bold"))

def write_error(t):
	t.pu()
	t.pensize(3)
	t.color('pink','white')
	t.goto(220,-270)
	t.fill(True)
	t.pd()
	t.goto(380,-270)
	t.goto(380,-305)
	t.goto(220,-305)
	t.goto(220,-270)
	t.fill(False)
	t.pu()
	t.pensize(1)
	t.goto(225,-300)
	t.color('red')
	t.write('Enter Atleast one Query Var',True,align="left",font=('Arial',8,"bold"))

countGUI=0
def writemb(markov_blanket):
	global countGUI
	countGUI+=1
	temp=str(markov_blanket)
	t=Turtle()
	t.speed(0)
	t.ht()
	t.pu()
	t.color('blue')
	if countGUI==1:
		t.goto(-130,290)
		t.write("MARKOV BLANKET(S):\nQuery Variables",True,align="left",font=('Arial',8,"bold"))
	t.goto(-130,270-countGUI*50)
	t.color('black')
	t.write(temp,True,align="left",font=('Arial',8,"bold"))

countGUI1=0
def writemb1(markov_blanket):
	global countGUI1
	countGUI1+=1
	temp=str(markov_blanket)
	t=Turtle()
	t.speed(0)
	t.ht()
	t.pu()
	t.color('blue')
	if countGUI1==1:
		t.goto(280,290)
		t.write("MARKOV BLANKET(S):\nCondition Variables",True,align="left",font=('Arial',8,"bold"))
	t.goto(280,270-countGUI1*50)
	t.color('black')
	t.write(temp,True,align="left",font=('Arial',8,"bold"))

def writeAns(t,ans):
	t.pu()
	t.color('black')
	t.goto(-295,-335)
	t.write("Answer : "+str(ans),True,align="left",font=("Arial", 12,"bold"))
	t.pensize(3)
	t.color('pink','white')
	t.goto(220,-270)
	t.fill(True)
	t.pd()
	t.goto(380,-270)
	t.goto(380,-305)
	t.goto(220,-305)
	t.goto(220,-270)
	t.fill(False)
	t.pu()
	t.pensize(1)
	t.goto(225,-300)
	t.color('red')
	t.goto(225,-300)
	t.write("Processing Done!",True,align="left",font=("Arial", 12,"bold"))







