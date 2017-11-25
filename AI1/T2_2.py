#2015A7PS0102P K S Sanjay Srivastav
from __future__ import print_function
from dirtGenerator import dirtGenerator,printRoom
from turtle import *
from T1 import findNearestRest
from GUI import UI_generator,T2_2_writer
import copy,turtle,sys
def getchil(state,explored,n):
	l=[]
	count=0
	if state[0]<n-1:
		l.append([state[0]+1,state[1],state[2]-1])
		count+=1
	if state[1]<n-1:
		l.append([state[0],state[1]+1,state[2]-1])
		count+=1
	if state[0]>0:
		l.append([state[0]-1,state[1],state[2]-1])
		count+=1
	if state[1]>0:
		l.append([state[0],state[1]-1,state[2]-1])
		count+=1
	k=0
	for i in range(count):
		for j in explored:
			if l[k][0]==j[0] and l[k][1]==j[1]:
				l.pop(k)
				k-=1
				break
		k+=1
	return l

def goalTest(explored,tile_list,n):
	flag=0
	if tile_list[explored[-1][0]][explored[-1][1]]==1:
		return 1
	return 0

def globalGoalTest(state,n):
	for i in range(n):
		for j in range(n):
			if state[i][j]==1:
				return 0
	return 1

def idfs2(max_depth,n,tile_list,no_nodes,total_mem,x=0,y=0,ind=0):
	explored=[]
	Stack=[]
	Stack.append([x,y,max_depth])
	total_mem+=sys.getsizeof(Stack[-1])
	no_nodes+=1
	while(len(Stack)>0):
		temp=Stack.pop()
		total_mem-=sys.getsizeof(temp)
		ex=explored[:]
		k=0
		for j in range(len(ex)):
			if len(explored)>0 and ex[j][2]<=temp[2]:
				t=explored.pop(k)
				total_mem-=sys.getsizeof(t)
				k-=1
			k+=1
		explored.append(temp)
		total_mem+=sys.getsizeof(explored[-1])
		no_nodes+=1
		if goalTest(explored,tile_list,n)==1:
			return explored,no_nodes,total_mem
		if temp[2]!=0:
			if ind==0:
				chil=getchil(temp,explored,n)
			else:
				chil=chilGenerator(temp,explored,n,tile_list)
			if len(chil)>0:
				for i in range(len(chil)-1,-1,-1):
					Stack.append(chil[i])
					total_mem+=sys.getsizeof(Stack[-1])
					no_nodes+=1
	return 0,no_nodes,total_mem

def compute_heuristic2(m2,x,y,tile_list,p,n,ind=0,opt=3):
	if globalGoalTest(tile_list,n)==1:
		return 0,[]
	if opt==4:
		m2.penup()
		m2.goto(x//6+x//60,y//2-y//40)
		m2.shape("turtle")
		m2.pendown()
		m2.pendown()
		m2.pencolor("green")
	no_nodes=0
	total_mem=0
	x1=0
	y1=0
	res=[]
	temp=[[],[],[],[]]
	temp2=[[0,0],[1,0],[2,0],[3,0]]
	for i in range(12):
		temp[0]=idfs2(i,n,tile_list,no_nodes,total_mem,0,0,ind)
		if temp[0][0]!=0:
			temp2[0][1]=len(temp[0][0])
			break
	
	for i in range(12):
		temp[1]=idfs2(i,n,tile_list,no_nodes,total_mem,0,n-1,ind)
		if temp[1][0]!=0:
			temp2[1][1]=len(temp[1][0])
			break
	
	for i in range(12):
		temp[2]=idfs2(i,n,tile_list,no_nodes,total_mem,n-1,0,ind)
		if temp[2][0]!=0:
			temp2[2][1]=len(temp[2][0])
			break
	
	for i in range(12):
		temp[3]=idfs2(i,n,tile_list,no_nodes,total_mem,n-1,n-1,ind)
		if temp[3][0]!=0:
			temp2[3][1]=len(temp[3][0])
			break
	temp2.sort(key=lambda z:z[1])
	bestrest=0
	for i in temp2:
		if i[1]!=0:
			bestrest=i[0]
			break
	bestStart={0:(0,0),1:(0,n-1),2:(n-1,0),3:(n-1,n-1)}
	if opt==4:
		m2.speed(0)
		m2.penup()
		m2.goto(bestStart[bestrest][1]*x//30+(1-ind)*(-1)*x//6+ind*x//6+x//60,-1*bestStart[bestrest][0]*y//20+y//2-y//40)
		m2.pendown()
		m2.speed(1)
	path=[]
	path=temp[bestrest][0]
	if path==0:
		path=[[0,0,0]]
		pathlen=0
		total_path=[]
	else:
		pathlen=len(path)
		total_path=path
	no_nodes+=temp[bestrest][1]
	# print(path)

	for i in path:
		if tile_list[i[0]][i[1]]==1:
			tile_list[i[0]][i[1]]=0
			# cleanDirt(x,y,i[0],i[1],0)
		if opt==4:
			m2.goto((1-ind)*(-1)*x//6+ind*x//6+x//60+i[1]*x//30,y//2-y//40-i[0]*y//20)
	x1=path[-1][0]
	y1=path[-1][1]
	total_path+=[[x1,y1]]
	c=1
	if globalGoalTest(tile_list,n)==1:
		res=[[x1,y1]],1
		no_nodes+=1
	else:
		c=0
		while True:
			c+=1
			if globalGoalTest(tile_list,n)==1:
				break
			for i in range(2*n*n):
				res=idfs2(i,n,tile_list,no_nodes,total_mem,x1,y1,ind)
				if res[0]!=0:
					break
			no_nodes+=res[1]
			total_mem+=res[2]
			path=res[0]
			total_path+=path[1:]
			x1=path[-1][0]
			y1=path[-1][1]
			pathlen+=len(res[0])
			# print(res,"hello")
			for i in path:
				if tile_list[i[0]][i[1]]==1:
					tile_list[i[0]][i[1]]=0
					# cleanDirt(x,y,i[0],i[1],0)
				if opt==4:
					m2.goto((1-ind)*(-1)*x//6+ind*x//6+x//60+i[1]*x//30,y//2-y//40-i[0]*y//20)
	sizeOfNode=sys.getsizeof(res[0][-1])
	extra_path=findNearestRest(res[0][-1],n)
	if len(extra_path)>0:
		total_mem+=(len(extra_path)*sys.getsizeof(extra_path[0]))
	no_nodes+=len(extra_path)
	# print(extra_path)
	pathlen+=len(extra_path)
	if opt==4:
		for i in extra_path:
			m2.goto((1-ind)*(-1)*x//6+ind*x//6+x//60+i[1]*x//30,y//2-y//40-i[0]*y//20)
	cost=2*pathlen-2*c+n*n*p//100
	if opt==3:
		print("Action Path for T2(h2) is ")
		for i in total_path:
			print(i[0],i[1])
		print("cost(T2(h2))= ",cost)
	if opt==4:
		T2_2_writer(x,y,p,n,no_nodes,cost,sizeOfNode,total_mem)
	return cost,total_path


def bottom_child(state,n,l,count):
	if state[0]<n-1 :
		l.append([state[0]+1,state[1],state[2]-1])
		count+=1
	return [l,count]
def right_child(state,n,l,count):
	if state[1]<n-1:
		l.append([state[0],state[1]+1,state[2]-1])
		count+=1
	return [l,count]
def top_child(state,n,l,count):
	if state[0]>0:
		l.append([state[0]-1,state[1],state[2]-1])
		count+=1
	return [l,count]
def left_child(state,n,l,count):
	if state[1]>0:
		l.append([state[0],state[1]-1,state[2]-1])
		count+=1
	return [l,count]

def chilGenerator(state,explored,n,tile_list):

	l=[]
	count=0
	if state[0]<n-1 and tile_list[state[0]+1][state[1]]==1:
		l,count=bottom_child(state,n,l,count)
		l,count=right_child(state,n,l,count)
		l,count=top_child(state,n,l,count)
		l,count=left_child(state,n,l,count)
	elif state[1]<n-1 and tile_list[state[0]][state[1]+1]==1:
		l,count=right_child(state,n,l,count)
		l,count=bottom_child(state,n,l,count)
		l,count=top_child(state,n,l,count)
		l,count=left_child(state,n,l,count)
	elif state[0]>0 and tile_list[state[0]-1][state[1]]==1:
		l,count=top_child(state,n,l,count)
		l,count=bottom_child(state,n,l,count)
		l,count=right_child(state,n,l,count)
		l,count=left_child(state,n,l,count)
	elif state[1]>0 and tile_list[state[0]][state[1]-1]==1:
		l,count=left_child(state,n,l,count)
		l,count=bottom_child(state,n,l,count)
		l,count=right_child(state,n,l,count)
		l,count=top_child(state,n,l,count)
	elif state[1]<n-1 and ((state[0]>0 and tile_list[state[0]-1][state[1]+1]==1) or (state[0]<n-1 and tile_list[state[0]+1][state[1]+1]))==1:
		l,count=right_child(state,n,l,count)
		l,count=bottom_child(state,n,l,count)
		l,count=top_child(state,n,l,count)
		l,count=left_child(state,n,l,count)
	elif state[1]>0 and ((state[0]>0 and tile_list[state[0]-1][state[1]-1]==1) or (state[0]<n-1 and tile_list[state[0]+1][state[1]-1]==1)):
		l,count=left_child(state,n,l,count)
		l,count=bottom_child(state,n,l,count)
		l,count=right_child(state,n,l,count)
		l,count=top_child(state,n,l,count)
	else:
		l,count=bottom_child(state,n,l,count)
		l,count=right_child(state,n,l,count)
		l,count=top_child(state,n,l,count)
		l,count=left_child(state,n,l,count)
	k=0
	for i in range(count):
		for j in explored:
			if l[k][0]==j[0] and l[k][1]==j[1]:
				l.pop(k)
				k-=1
				break
		k+=1
	return l



# def compute_heuristic2(tile_list,n):






