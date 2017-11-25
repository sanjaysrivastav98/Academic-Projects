#2015A7PS0102P K S Sanjay Srivastav
from __future__ import print_function
from GUI import getCentre,getCentreCoor,drawCoin,dialogBox,clearBoard,drawBoard,write_minmax,write_ab
from turtle import *
from datetime import datetime
import turtle,sys
import copy,random


no_of_nodes=0
no_of_nodes_ab=0
time=0
temp_stack=0
stack=0
class humanMove:
	def __init__(self,state):
		self.state=state
	def Hmove(self,x,y):
		x,y=getCentreCoor(x,y)
		if x!=-1000 and self.state[0][x][y]==0:
			for i in successors(self.state,-1):
				if i[0][x][y]==-1:
					x,y=getCentre(x,y)
					drawCoin(x,y,-1)
					self.state=i
					if Terminal_test(self.state,-1):
						print("You Won")
						turtle.onscreenclick(None)
						dialogBox(-1)
						newGame()
						break
					self.state=Successor_function(self.state)
					x,y=getCentre(self.state[1],self.state[2])
					drawCoin(x,y,1)
					if Terminal_test(self.state,1):
						print("Machine Won")
						turtle.onscreenclick(None)
						dialogBox(1)
						newGame()
					break	


class humanMove_ab:
	def __init__(self,state):
		self.state=state
	def Hmove(self,x,y):
		x,y=getCentreCoor(x,y)
		if x!=-1000 and self.state[0][x][y]==0:
			for i in successors(self.state,-1):
				if i[0][x][y]==-1:
					x,y=getCentre(x,y)
					drawCoin(x,y,-1)
					self.state=i
					if Terminal_test(self.state,-1):
						print("You Won")
						turtle.onscreenclick(None)
						dialogBox(-1)
						newGame_ab()
						break
					self.state=Successor_function_ab(self.state)
					x,y=getCentre(self.state[1],self.state[2])
					drawCoin(x,y,1)
					if Terminal_test(self.state,1):
						print("Machine Won")
						turtle.onscreenclick(None)
						dialogBox(1)
						newGame_ab()
					break	

def printMat(state):
	s=state[0]
	for i in s:
		for j in i:
			print(j,end=" ")
		print()

def successors(state,ind):
	children=[]
	for j in range(4):
		for i in range(4):
			if state[0][i][j]==0:
				s=copy.deepcopy(state[0])
				s[i][j]=ind
				children.append([s,i,j])
				break
	return children

def Terminal_test(state,ind):
	s=state[0]
	i=state[1]
	j=state[2]
	if i==0:
		if j==0:
			if s[0][1]==ind and s[0][2]==ind or\
			 s[1][0]==ind and s[2][0]==ind or\
			  s[1][1]==ind and s[2][2]==ind:
				return True
		elif j==1:
			if s[0][0]==ind and s[0][2]==ind or\
				s[0][2]==ind and s[0][3]==ind or\
				s[1][1]==ind and s[2][1]==ind or\
				s[1][2]==ind and s[2][3]==ind:
				return True
		elif j==2:
			if s[0][0]==ind and s[0][1]==ind or\
				s[0][1]==ind and s[0][3]==ind or\
				s[1][2]==ind and s[2][2]==ind or\
				s[1][1]==ind and s[2][0]==ind:
				return True
		else:
			if s[0][1]==ind and s[0][2]==ind or\
			 s[1][3]==ind and s[2][3]==ind or\
			  s[1][2]==ind and s[2][1]==ind:
				return True
			elif s[3][1]!=0 and s[3][2]!=0 and s[3][3]!=0:
				return True
	elif i==1:
		if j==0:
			if s[1][1]==ind and s[1][2]==ind or\
			 s[2][0]==ind and s[3][0]==ind or\
			 s[0][0]==ind and s[2][0]==ind or\
			  s[2][1]==ind and s[3][2]==ind :
				return True
		elif j==1:
			if s[0][1]==ind and s[2][1]==ind or\
				s[2][1]==ind and s[3][1]==ind or\
				s[1][0]==ind and s[1][2]==ind or\
				s[1][2]==ind and s[1][3]==ind or\
				s[0][0]==ind and s[2][2]==ind or\
				s[2][2]==ind and s[3][3]==ind or\
				s[2][0]==ind and s[0][2]==ind:
				return True
		elif j==2:
			if s[0][2]==ind and s[2][2]==ind or\
				s[2][2]==ind and s[3][2]==ind or\
				s[1][1]==ind and s[1][3]==ind or\
				s[1][0]==ind and s[1][1]==ind or\
				s[3][0]==ind and s[2][1]==ind or\
				s[2][1]==ind and s[3][0]==ind or\
				s[0][1]==ind and s[2][3]==ind:
				return True
		else:
			if s[0][3]==ind and s[2][3]==ind or\
			 s[2][3]==ind and s[3][3]==ind or\
			 s[1][1]==ind and s[1][2]==ind or\
			  s[2][2]==ind and s[3][1]==ind :
				return True
			elif s[3][0]!=0 and s[3][2]!=0 and s[3][3]!=0:
				return True
	elif i==2:
		if j==0:
			if s[2][1]==ind and s[2][2]==ind or\
			 s[1][0]==ind and s[3][0]==ind or\
			 s[0][0]==ind and s[1][0]==ind or\
			  s[1][1]==ind and s[0][2]==ind :
				return True
		elif j==1:
			if s[0][1]==ind and s[1][1]==ind or\
				s[1][1]==ind and s[3][1]==ind or\
				s[2][0]==ind and s[2][2]==ind or\
				s[2][2]==ind and s[2][3]==ind or\
				s[1][0]==ind and s[3][2]==ind or\
				s[1][2]==ind and s[3][0]==ind or\
				s[1][2]==ind and s[0][3]==ind:
				return True
		elif j==2:
			if s[0][2]==ind and s[1][2]==ind or\
				s[1][2]==ind and s[3][2]==ind or\
				s[2][1]==ind and s[2][3]==ind or\
				s[2][0]==ind and s[2][1]==ind or\
				s[3][1]==ind and s[1][3]==ind or\
				s[1][1]==ind and s[3][3]==ind or\
				s[0][0]==ind and s[1][1]==ind:
				return True
		else:
			if s[2][1]==ind and s[2][2]==ind or\
			 s[1][3]==ind and s[3][3]==ind or\
			 s[1][3]==ind and s[0][3]==ind or\
			  s[1][2]==ind and s[0][1]==ind :
				return True
			elif s[3][1]!=0 and s[3][0]!=0 and s[3][3]!=0:
				return True
	else:
		if j==0:
			if s[1][0]==ind and s[2][0]==ind or\
			 s[3][1]==ind and s[3][2]==ind or\
			  s[2][1]==ind and s[1][2]==ind:
				return True
		elif j==1:
			if s[3][0]==ind and s[3][2]==ind or\
				s[3][2]==ind and s[3][3]==ind or\
				s[1][1]==ind and s[2][1]==ind or\
				s[2][2]==ind and s[1][3]==ind:
				return True
		elif j==2:
			if s[3][0]==ind and s[3][1]==ind or\
				s[3][1]==ind and s[3][3]==ind or\
				s[1][2]==ind and s[2][2]==ind or\
				s[1][0]==ind and s[2][1]==ind:
				return True
		else:
			if s[3][1]==ind and s[3][2]==ind or\
			 s[1][3]==ind and s[2][3]==ind or\
			  s[1][1]==ind and s[2][2]==ind:
				return True
			elif s[3][1]!=0 and s[3][2]!=0 and s[3][0]!=0:
				return True
	return False

def Max_Value(state):
	global stack
	global temp_stack
	global no_of_nodes
	temp_stack+=1
	if Terminal_test(state,-1):
		if temp_stack>stack:
			stack=temp_stack
		temp_stack=0
		return -1
	v=-10000
	m=0
	for i in successors(state,1):
		no_of_nodes+=1
		m=Min_Value(i)
		v=max(v,m)
	if v==-10000:
		return 0
	return v

def Min_Value(state):
	global stack
	global temp_stack
	global no_of_nodes
	temp_stack+=1
	if Terminal_test(state,1):
		if temp_stack>stack:
			stack=temp_stack
		temp_stack=0
		return 1
	v=10000
	m=0
	for i in successors(state,-1):
		no_of_nodes+=1
		m=Max_Value(i)
		v=min(v,m)
	if v==10000:
		return 0
	return v

def Successor_function(state):
	v=-10000
	global no_of_nodes
	global time
	global stack
	global temp_stack
	start=datetime.now()
	s=state
	for i in successors(state,1):
		m=Min_Value(i)
		no_of_nodes+=1
		temp_stack+=1
		v1=max(v,m)
		if v1!=v:
			s=i
		v=v1
		# print("here",v)
	end=datetime.now()
	time1=(end-start)
	time+=time1.total_seconds()
	write_minmax(no_of_nodes,sys.getsizeof(state),stack,time)

	return s

def runMinimax():
	s=[[0 for i in range(4)] for j in range(4)]
	p=random.randint(0,3)
	s[0][p]=1
	state=[s,0,p]
	global no_of_nodes
	global time
	global stack
	time=0
	stack=0
	no_of_nodes=1
	# # state=Successor_function(state)
	x,y=getCentre(state[1],state[2])
	drawCoin(x,y,1)
	h=humanMove(state)
	turtle.onscreenclick(h.Hmove)
	state=h.state
	# printMat(state)




class newGamer:
	def isClicked(self,x,y):
		if x<=400 and x>=200 and y<=-250 and y >=-290:
			clearBoard()
			drawBoard()
			runMinimax()
class newGamer_ab:
	def isClicked(self,x,y):
		if x<=400 and x>=200 and y<=-250 and y >=-290:
			clearBoard()
			drawBoard()
			run_alpha_beta()
def newGame():
	h=newGamer()
	turtle.onscreenclick(h.isClicked)
def newGame_ab():
	h=newGamer_ab()
	turtle.onscreenclick(h.isClicked)

def Max_Value_ab(state,a,b):
	global no_of_nodes_ab
	if Terminal_test(state,-1):
		return -1
	v=-10000
	m=0
	for i in successors(state,1):
		m=Min_Value_ab(i,a,b)
		no_of_nodes_ab+=1
		v=max(v,m)
		if v>=b:
			return v
		a=max(a,v)
	if v==-10000:
		return 0
	return v

def Min_Value_ab(state,a,b):
	global no_of_nodes_ab
	if Terminal_test(state,1):
		return 1
	v=10000
	m=0
	for i in successors(state,-1):
		m=Max_Value_ab(i,a,b)
		v=min(v,m)
		no_of_nodes_ab+=1
		if v<=a :
			return v
		b=min(b,v)
	if v==10000:
		return 0
	return v

def Successor_function_ab(state):
	v=-10000 
	global no_of_nodes_ab
	global time_ab
	start=datetime.now()
	s=state
	a=-10000
	b=10000
	for i in successors(state,1):
		no_of_nodes_ab+=1
		m=Min_Value_ab(i,a,b)
		v1=max(v,m)
		if v1!=v:
			s=i
		v=v1
		a=max(a,v)
	end=datetime.now()
	time1=(end-start)
	time_ab+=time1.total_seconds()
	write_ab(no_of_nodes_ab,time_ab)
	return s

def run_alpha_beta():
    s=[[0 for i in range(4)] for j in range(4)]
    state=[s,0,0]
    global no_of_nodes_ab
    global time_ab
    time_ab=0
    no_of_nodes_ab=0
    state=Successor_function_ab(state)
    x,y=getCentre(state[1],state[2])
    drawCoin(x,y,1)
    h=humanMove_ab(state)
    turtle.onscreenclick(h.Hmove)
    state=h.state




	
	


