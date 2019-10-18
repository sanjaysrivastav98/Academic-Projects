#2015A7PS0102P K S Sanjay Srivastav
from __future__ import print_function
from dirtGenerator import dirtGenerator,printRoom
from turtle import *
from datetime import datetime
from T1 import findNearestRest,idfs,idfs_caller
from T2_1 import compute_heuristic1
from T2_2 import compute_heuristic2
from GUI import UI_generator,G3_generator,G4_generator
import turtle,copy,random

def main():
	opt=0
	while(opt!=1):
		opt=int(raw_input("Enter an option "))
		n=10
		if opt==1:
			p=int(raw_input("Enter the percentage of tiles having dirt "))
			tile_list=dirtGenerator(p,n)
			win=Screen()
			tile_list_copy1=copy.deepcopy(tile_list)
			tile_list_copy2=copy.deepcopy(tile_list)
			tile_list_copy3=copy.deepcopy(tile_list)
			x,y=UI_generator(win,tile_list,n)
	
			break
		else:
			print("Please Enter 1 to start ")
	
	opt=int(raw_input("Enter 2 or 3 to find the path and 4 to prompt graphics "))
	
	#using T2 method
	m2=Turtle()
	m2.pensize(6)
	m3=Turtle()
	m3.pensize(3)
	temp_m=Turtle()
	t1start=datetime.now()
	compute_heuristic1(m2,x,y,tile_list_copy2,p,n,1,opt)
	t1end=datetime.now()
	delta=t1end-t1start
	if opt==4:
		temp_m.penup()
		temp_m.goto(-1*x//2+90,y//2-30-8*y//11)
		delta=delta.total_seconds()
		temp_m.write("h1 "+str(round(delta,3))+" sec",align="center",font=("Arial", 12,"bold"))
		temp_m.penup()
	

	t1start=datetime.now()
	compute_heuristic2(m3,x,y,tile_list_copy3,p,n,1,opt)
	t1end=datetime.now()
	delta=t1end-t1start
	if opt==4:
		temp_m.penup()
		temp_m.goto(-1*x//2+110,y//2-50-8*y//11)
		delta=delta.total_seconds()
		temp_m.write("h2 "+str(round(delta,3))+" sec",align="center",font=("Arial", 12,"bold"))
		temp_m.penup()
	

	ave_cost_t1=0
	ave_cost_h1=0
	ave_cost_h2=0
	tile_list_R11=[]
	
	if opt==4:
		#plotting G3
		time_list_h1=[]
		p1=random.randint(1,100)
		m3=Turtle()
		m3.penup()
		for i in range(3,11):
			tile_list=dirtGenerator(p1,i)
			t1_start=datetime.now()
			compute_heuristic1(m3,x,y,tile_list,p1,i,1,-1)
			t1_end=datetime.now()
			delta=t1end-t1start
			time_list_h1.append(delta.total_seconds()*1000*1000)
		time_list_h2=[]
		m3=Turtle()
		m3.penup()
		for i in range(3,11):
			tile_list=dirtGenerator(p1,i)
			t1_start=datetime.now()
			compute_heuristic2(m3,x,y,tile_list,p1,i,1,-1)
			t1_end=datetime.now()
			delta=t1end-t1start
			time_list_h2.append(delta.total_seconds()*1000*1000)
		m3=Turtle()
		m3.hideturtle()
		m3.color("blue")
		G3_generator(m3,time_list_h1)
		m3=Turtle()
		m3.hideturtle()
		m3.color("green")
		G3_generator(m3,time_list_h2)

		#G4
		m3=Turtle()
		m3.hideturtle()
		m3.color("green")
		time_list_dirt=[]
		for i in range(10,100,5):
			tile_list=dirtGenerator(i,10)
			t1_start=datetime.now()
			compute_heuristic2(m3,x,y,tile_list,i,10,1,-1)
			t1_end=datetime.now()
			delta=t1end-t1start
			time_list_dirt.append(delta.total_seconds()*1000*1000)
		G4_generator(m3,time_list_dirt)

	m=Turtle()
	m.pensize(3)
	t1start=datetime.now()
	idfs_caller(m,x,y,tile_list_copy1,p,n,0,opt)
	t1end=datetime.now()
	delta=t1end-t1start
	if opt==4:
		temp_m.penup()
		temp_m.goto(-1*x//2+90,y//2-30-4*y//11)
		delta=delta.total_seconds()
		temp_m.write(str(round(delta,3))+" sec",align="center",font=("Arial", 12,"bold"))
		temp_m.penup()
		temp_m.hideturtle()
		m=Turtle()

		#R11 analysis
		for i in range(10):
			p1=random.randint(1,100)
			tile_list_R11=dirtGenerator(p1,n)
			temp_tile_list=copy.deepcopy(tile_list_R11)
			temp_tile_list2=copy.deepcopy(tile_list_R11)
			temp=idfs_caller(m,x,y,temp_tile_list,p1,n,1,-1)
			ave_cost_t1+=temp[0]
			temp2=compute_heuristic2(m3,x,y,temp_tile_list2,p1,n,1,-1)
			ave_cost_h2+=temp2[0]
		ave_cost_t1=ave_cost_t1//10
		ave_cost_h2=ave_cost_h2//10
		temp_m.penup()
		temp_m.goto(-1*x//2+120,y//2-30-10*y//11)
		temp_m.write("T1 "+str(ave_cost_t1),align="center",font=("Arial", 12,"bold"))
		temp_m.penup()
		temp_m.goto(-1*x//2+120,y//2-50-10*y//11)
		temp_m.write("T2(h2) "+str(ave_cost_h2),align="center",font=("Arial", 12,"bold"))
		temp_m.penup()
		temp_m.hideturtle()
	win.exitonclick()

print("Test code")
actionMap={
	-1:'init',
	0:'sweep',
	1:'move left',
	2:'move right',
	3:'move up',
	4:'move down'
}
main()
