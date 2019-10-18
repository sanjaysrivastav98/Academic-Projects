#2015A7PS0102P K S Sanjay Srivastav
from __future__ import print_function
from turtle import *
import turtle

def fillcolors(t,tile_list,ind,x,y,n):
	if ind==1:
		x_start=-1*x//6
	else:
		x_start=x//6
	t.penup()
	t.speed(0)
	for i in range(n):
		for j in range(n):
			if tile_list[j][i]==1:
				t.color("black","grey")
				t.goto(x_start+i*x//30,y//2-j*y//20)
				t.pendown()
				t.fill(True)
				for k in range(4):
					if k%2==0:
						t.forward(x//30)
					else:
						t.forward(y//20)
					t.right(90)
				t.fill(False)
				t.penup()
	t.hideturtle()

def drawGrid(t,x,y,ind):
	t.speed(0)
	if ind==1:
		x_start=-1*x//6
	else:
		x_start=x//6
	for i in range(10):
		t.penup()
		t.goto(x_start,y//2-i*y//20)
		t.pendown()
		t.forward(x//3)
	t.penup()
	t.right(90)
	for i in range(10):
		t.penup()
		t.goto(x_start+(i*x)//30,y//2)
		t.pendown()
		t.forward(y//2)
	t.left(90)


def cleanDirt(x,y,i,j,ind):
	turt=Turtle()
	turt.hideturtle()
	if ind==2:
		x_start=-1*x//6+j*x//30
	else:
		x_start=x//6+j*x//30
	turt.penup()
	turt.goto(x_start,y//2-i*y//20)
	if ind==2:
		turt.color('black','cyan')
	else:
		turt.color('black',"yellow")
	turt.pendown()
	turt.fill(True)
	for k in range(4):
		if k%2==0:
			turt.forward(x//30)
		else:
			turt.forward(y//20)
		turt.right(90)
	turt.fill(False)

def UI_generator(win,tile_list,n):
	t=Turtle()
	turtle.setup(920,600)
	t.pensize(2)
	t.hideturtle()
	t.speed(0)
	t.penup()
	t.right(90)
	x=900
	y=600
	t.goto(-1*x//6,y//2)
	t.pendown()
	t.forward(y)
	t.penup()
	t.goto(-1*x//6,0)
	t.left(90)
	t.pendown()
	t.forward(2*x//3)
	t.penup()
	t.goto(x//6,y//2)
	t.right(90)
	t.pendown()
	t.forward(y)
	t.penup()
	t.left(90)
	t.goto(-1*x//2+10,y//2-10)
	turt=Turtle()
	turt.penup()
	turt.speed(0)
	
	for i in range(11):
		turt.goto(-1*x//2+30,y//2-30-i*y//11)
		turt.write("R"+str(i+1),True,align="center",font=("Arial", 12,"bold") )
	drawGrid(turt,x,y,1)
	drawGrid(turt,x,y,0)
	fillcolors(turt,tile_list,1,x,y,n)
	fillcolors(turt,tile_list,0,x,y,n)
	return x,y

def T1_writer(x,y,p,n,no_nodes,cost,sizeOfNode,total_mem,max_stack):
	m2=Turtle()
	m2.penup()
	m2.goto(-1*x//2+110,y//2-30-3*y//11)
	m2.pendown()
	m2.write(str(cost)+" cost",align="center",font=("Arial", 12,"bold"))
	m2.penup()
	m2.goto(-1*x//2+110,y//2-30-0*y//11)
	m2.write(str(no_nodes)+" nodes",align="center",font=("Arial", 12,"bold"))
	m2.penup()
	m2.goto(-1*x//2+110,y//2-30-1*y//11)
	m2.write(str(sizeOfNode),align="center",font=("Arial", 12,"bold"))
	m2.penup()
	m2.goto(-1*x//2+90,y//2-30-9*y//11)
	m2.write("T1 - "+str(round(total_mem/1024,3))+"KB",align="center",font=("Arial", 12,"bold"))
	m2.penup()
	m2.goto(-1*x//2+110,y//2-30-2*y//11)
	m2.write(str(max_stack),align="center",font=("Arial", 12,"bold"))
	m2.penup()
	m2.hideturtle()

def T2_1_writer(x,y,p,n,no_nodes,cost,sizeOfNode,total_mem):
	m2=Turtle()
	m2.penup()
	m2.goto(-1*x//2+100,y//2-30-7*y//11)
	m2.pendown()
	m2.write("h1 "+str(cost)+" cost",align="center",font=("Arial", 12,"bold"))
	m2.penup()
	m2.goto(-1*x//2+100,y//2-30-5*y//11)
	m2.pendown()
	m2.write("h1 "+str(no_nodes)+" nodes",align="center",font=("Arial", 12,"bold"))
	m2.penup()
	m2.goto(-1*x//2+100,y//2-30-6*y//11)
	m2.pendown()
	m2.write("h1 "+str(sizeOfNode)+"B",align="center",font=("Arial", 12,"bold"))
	m2.penup()
	m2.goto(-1*x//2+200,y//2-30-9*y//11)
	m2.pendown()
	m2.write("T2(h1) "+str(round(total_mem/1024,3))+"KB",align="center",font=("Arial", 12,"bold"))
	m2.penup()
	m2.hideturtle()

def T2_2_writer(x,y,p,n,no_nodes,cost,sizeOfNode,total_mem):
	m2=Turtle()
	m2.penup()
	m2.goto(-1*x//2+100,y//2-50-7*y//11)
	m2.pendown()
	m2.write("h2 "+str(cost)+" cost",align="center",font=("Arial", 12,"bold"))
	m2.penup()
	m2.goto(-1*x//2+100,y//2-50-5*y//11)
	m2.pendown()
	m2.write("h2 "+str(no_nodes) +" nodes",align="center",font=("Arial", 12,"bold"))
	m2.penup()
	m2.goto(-1*x//2+100,y//2-50-6*y//11)
	m2.pendown()
	m2.write("h2 "+str(sizeOfNode)+"B",align="center",font=("Arial", 12,"bold"))
	m2.penup()
	m2.goto(-1*x//2+170,y//2-50-9*y//11)
	m2.pendown()
	m2.write("T2(h2)- "+str(round(total_mem/1024,3))+" KB",align="center",font=("Arial", 12,"bold"))
	m2.penup()
	m2.hideturtle()


def G3_generator(m,list1):
	ul=max(list1)
	m.penup()
	m.goto(-140,-270)
	m.pd()
	for i in range(11):
		m.goto(i*28-140,-270)
		m.pu()
		m.goto(i*28-140,-280)
		m.write(str(i),align="center",font=("Arial", 8,"bold"))
		m.goto(i*28-140,-270)
		m.pd()
	m.pu()
	m.left(90)
	m.goto(-140,-10)
	m.pd()
	ul=ul%260
	if ul>0:
		ul=ul%12
	ul=int(ul)+1
	for i in range(int(ul)):
		m.goto(-140,-270+i*260//ul)
		m.pu()
		m.goto(-145,-270+i*260//(ul))
		m.write(str(i*12*260),align="center",font=("Arial", 8,"bold"))
		m.goto(-140,-270+i*260//(ul))
		m.pd()
	m.pu()
	m.goto(-140,-270)
	m.pd()
	for i in range(len(list1)):
		m.goto(-140+(i+3)*28,-270+int((list1[i]%260)%12)*260//ul)
	m.pd()

def G4_generator(m,list1):
	ul=max(list1)
	m.penup()
	m.goto(160,-270)
	m.pd()
	for i in range(21):
		m.goto(i*14+160,-270)
		m.pu()
		m.goto(i*14+160,-280)
		m.write(str(5*i),align="center",font=("Arial", 8,"bold"))
		m.goto(i*14+160,-270)
		m.pd()
	m.pu()
	m.left(90)
	m.goto(160,-270)
	m.pd()
	ul=ul%260
	if ul>0:
		ul=ul%12
	ul=int(ul)+1
	for i in range(int(ul)):
		m.goto(160,-270+i*260//ul)
		m.pu()
		m.goto(155,-270+i*260//(ul))
		m.write(str(i*12*260),align="center",font=("Arial", 8,"bold"))
		m.goto(160,-270+i*260//(ul))
		m.pd()
	m.pu()
	m.goto(160,-270)
	m.pd()
	for i in range(len(list1)):
		m.goto(160+(i+2)*14,-270+int((list1[i]%260)%12)*260//ul)
	m.pd()





