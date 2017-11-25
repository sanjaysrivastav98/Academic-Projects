#2015A7PS0102P K S Sanjay Srivastav

from turtle import *
import turtle
import Tkinter
import tkMessageBox




def drawBoard():
	t=Turtle()
	t.hideturtle()
	t.pensize(2)
	t.penup()
	t.speed(0)
	t.goto(-100,250)
	t.color("red")
	t.pensize(6)
	t.pendown()
	t.goto(400,250)
	t.penup()
	t.color('black')
	t.pensize(1)
	t.goto(150,270)
	t.write("base line ",True,align="center",font=("Arial", 12,"bold"))
	t.goto(-50,200)
	for i in range(5):
		t.penup()
		t.goto(-50,200-i*100)
		t.pendown()
		t.goto(350,200-i*100)
	t.right(90)
	for i in range(5):
		t.penup()
		t.goto(-50+100*i,200)
		t.pendown()
		t.goto(-50+100*i,-200)
	t.penup()
	for i in range(4):
		t.goto(-75,150-100*i)
		t.write("R"+str(i+1),True,align="center",font=("Arial", 12,"bold") )
		t.goto(0+100*i,-230)
		t.write("C"+str(i+1),True,align="center",font=("Arial", 12,"bold") )


def getCentre(x,y):
	return (100*y,100-100*x)

def drawCoin(x,y,ind):
	t=Turtle()
	t.penup()
	t.speed(0)
	t.hideturtle()
	if ind==1:
		t.color('black','green')
	else:
		t.color('black','blue')
	t.goto(x,y)
	t.fill(True)
	t.pendown()
	t.begin_fill()
	t.circle(50)
	t.end_fill()
	t.penup()

def getCentreCoor(x,y):
	for i in range(4):
		for j in range(4):
			if x in range(-50+j*100,50+j*100) and y in range(200-100*i,100-100*i,-1):
				return i,j
	return -1000,-1000


																																																																																																																																																																																																								

def main_window():
	t=Turtle()
	turtle.setup(920,620)
	t.pensize(2)
	t.hideturtle()
	t.speed(0)
	t.penup()
	t.goto(-450,300)
	t.pendown()
	t.goto(450,300)
	t.goto(450,-300)
	t.goto(-450,-300)
	t.goto(-450,300)
	t.penup()
	t.right(90)
	t.goto(-150,300)
	t.pendown()
	t.forward(600)
	t.penup()

	turt=Turtle()
	turt.penup()
	turt.speed(0)
	turt.hideturtle()
	for i in range(12):
		turt.goto(-1*900//2+30,600//2-30-i*600//12)
		turt.write("R"+str(i+1),True,align="center",font=("Arial", 12,"bold") )
	drawBoard()		

def clearBoard():
	t=Turtle()
	t.hideturtle()
	t.speed(0)
	t.color('white')
	t.penup()
	t.goto(-130,295)
	t.fill(True)
	t.pendown()
	t.begin_fill()
	t.goto(430,295)
	t.goto(430,-295)
	t.goto(-130,-295)
	t.goto(-130,295)
	t.end_fill()
	t.penup()


def dialogBox(ind):
	t=Turtle()
	t.speed(0)
	t.pensize(4)
	t.hideturtle()
	t.penup()
	t.goto(0,-280)
	if ind==1:
		t.write("Machine (M) won",True,align="center",font=("Arial", 12,"bold"))
	else:
		t.write("You (H) won",True,align="center",font=("Arial", 12,"bold"))
	t.goto(200,-250)
	t.color('black','grey')
	t.fill(True)
	t.begin_fill()
	t.pendown()
	t.goto(400,-250)
	t.goto(400,-290)
	t.goto(200,-290)
	t.goto(200,-250)
	t.end_fill()
	t.penup()
	t.pensize(1)
	t.color('red')
	t.goto(300,-280)
	t.write("New Game",True,align="center",font=("Arial", 12,"bold"))


def writeR1(no_of_nodes):
	clear_R(0)
	t=Turtle()
	t.speed(0)
	t.hideturtle()
	t.penup()
	t.goto(-1*900//2+100,600//2-30)
	t.write(str(no_of_nodes) +' nodes',True,align="center",font=("Arial", 12,"bold") )

def writeR2(memory):
	clear_R(1)
	t=Turtle()
	t.speed(0)
	t.hideturtle()
	t.penup()
	t.goto(-1*900//2+100,600//2-30-1*600//12)
	t.write(str(memory)+' Bytes',True,align="center",font=("Arial", 12,"bold") )

def writeR3(memory):
	clear_R(2)
	t=Turtle()
	t.speed(0)
	t.hideturtle()
	t.penup()
	t.goto(-1*900//2+100,600//2-30-2*600//12)
	t.write(str(memory)+' max stack',True,align="center",font=("Arial", 12,"bold") )

def writeR4(time):
	clear_R(3)
	t=Turtle()
	t.speed(0)
	t.hideturtle()
	t.penup()
	t.goto(-1*900//2+100,600//2-30-3*600//12)
	t.write(str(time)+' sec',True,align="center",font=("Arial", 12,"bold") )

def writeR5(no_of_nodes,time):
	clear_R(4)
	n=no_of_nodes/time
	n=n/1000000
	t=Turtle()
	t.speed(0)
	t.hideturtle()
	t.penup()
	t.goto(-1*900//2+150,600//2-30-4*600//12)
	t.write(str(round(n,3))+' nodes/microsec',True,align="center",font=("Arial", 12,"bold") )



def writeR6(no_of_nodes):
	clear_R(5)
	t=Turtle()
	t.speed(0)
	t.hideturtle()
	t.penup()
	t.goto(-1*900//2+100,600//2-30-5*600//12)
	t.write(str(no_of_nodes)+' nodes',True,align="center",font=("Arial", 12,"bold") )

def writeR7(no_of_nodes,no_of_nodes_ab):
	clear_R(6)
	s=(float(no_of_nodes)-float(no_of_nodes_ab))/float(no_of_nodes)
	t=Turtle()
	t.speed(0)
	t.hideturtle()
	t.penup()
	t.goto(-1*900//2+100,600//2-30-6*600//12)
	t.write(str(round(s,3)),True,align="center",font=("Arial", 12,"bold") )

def writeR8(time):
	clear_R(7)
	t=Turtle()
	t.speed(0)
	t.hideturtle()
	t.penup()
	t.goto(-1*900//2+100,600//2-30-7*600//12)
	t.write(str(time)+' sec',True,align="center",font=("Arial", 12,"bold") )

def writeR9(no_of_nodes,no_of_nodes_ab):
	clear_R(8)
	t=Turtle()
	t.speed(0)
	t.hideturtle()
	t.penup()
	t.goto(-1*900//2+150,600//2-30+10-8*600//12)
	t.write('Minimax:'+str(no_of_nodes*88)+' Bytes',True,align="center",font=("Arial", 12,"bold") )
	t.goto(-1*900//2+150,600//2-30-10-8*600//12)
	t.write('Alpha-Beta:'+str(no_of_nodes_ab*88)+' Bytes',True,align="center",font=("Arial", 12,"bold") )

def writeR10():
	clear_R(9)
	t=Turtle()
	t.speed(0)
	t.hideturtle()
	t.penup()
	t.goto(-1*900//2+100,600//2-30-9*600//12)
	t.write(str(0.439)+' sec',True,align="center",font=("Arial", 12,"bold") )

def writeR11():
	clear_R(10)
	t=Turtle()
	t.speed(0)
	t.hideturtle()
	t.penup()
	t.goto(-1*900//2+100,600//2-30-10*600//12)
	t.write(str(10),True,align="center",font=("Arial", 12,"bold") )

def writeR12():
	clear_R(11)
	t=Turtle()
	t.speed(0)
	t.hideturtle()
	t.penup()
	t.goto(-1*900//2+100,600//2-30-11*600//12)
	t.write(str(10),True,align="center",font=("Arial", 12,"bold") )

def clear_R(i):
	t=Turtle()
	t.speed(0)
	t.hideturtle()
	t.penup()
	t.goto(-1*900//2+50,600//2+30-30-i*600//12)
	t.pendown()
	t.color('white')
	t.fill(True)
	t.begin_fill()
	t.goto(-160,600//2+30-30-i*600//12)
	t.goto(-160,600//2-30-30-i*600//12)
	t.goto(-1*900//2+50,600//2-30-30-i*600//12)
	t.goto(-1*900//2+50,600//2+30-30-i*600//12)
	t.end_fill()

def write_minmax(no_of_nodes,memory,stack,time):
	writeR1(no_of_nodes)
	writeR2(memory)
	writeR3(stack)
	writeR4(time)
	writeR5(no_of_nodes,time)

def write_ab(no_of_nodes_ab,time_ab):
	writeR6(no_of_nodes_ab)
	writeR7(562320,no_of_nodes_ab)
	writeR8(time_ab)

def writeAll():
	write_minmax(562320,88,16,14.51)
	write_ab(14297,0.408)
	writeR9(562320,14297)
	writeR10()
	writeR11()
	writeR12()


def close_main_window():
	turtle.mainloop()
	
