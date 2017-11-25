#2015A7PS0102P K S Sanjay Srivastav
from __future__ import print_function
from dirtGenerator import dirtGenerator,printRoom
from turtle import *

from T1 import findNearestRest
from GUI import UI_generator,T2_1_writer
import copy,turtle,sys
def goalTest_bfs(temp,tile_list,n):
	if tile_list[temp[0]][temp[1]]==1:
		return 1
	else:
		return 0

def globalGoalTest(state,n):
	for i in range(n):
		for j in range(n):
			if state[i][j]==1:
				return 0
	return 1

def getchil_bfs(state,n):
	l=[]
	count=0
	if state[0]<n-1:
		chil=[state[0]+1,state[1],state[2]+[[state[0]+1,state[1]]]]
		l.append(chil)
		count+=1
	if state[1]<n-1:
		chil=[state[0],state[1]+1,state[2]+[[state[0],state[1]+1]]]
		l.append(chil)
		count+=1
	if state[0]>0:
		chil=[state[0]-1,state[1],state[2]+[[state[0]-1,state[1]]]]
		l.append(chil)
		count+=1
	if state[1]>0:
		chil=[state[0],state[1]-1,state[2]+[[state[0],state[1]-1]]]
		l.append(chil)
		count+=1
	k=0
	for i in range(count):
		for j in state[2]:
			if l[k][0]==j[0] and l[k][1]==j[1]:
				l.pop(k)
				k-=1
				break
		k+=1
	return l

def bfs(tile_list,n,ind,x1,y1,no_nodes,total_mem):
	Q=[]
	Q.append([x1,y1,[	]])
	total_mem+=sys.getsizeof(Q[-1])
	no_nodes+=1
	while(len(Q)>0):
		# print(len(Q))
		temp=Q.pop(0)
		total_mem-=sys.getsizeof(temp)
		if goalTest_bfs(temp,tile_list,n)==1:
			return temp,no_nodes,total_mem
		if ind==0:
			chil=getchil_bfs(temp,n)
		else:
			chil=chilGenerator_bfs(temp,n,tile_list)
		for i in chil:
			Q.append(i)
			total_mem+=sys.getsizeof(Q[-1])
			no_nodes+=1
	return 0,no_nodes,total_mem

def compute_heuristic1(m,x,y,tile_list,p,n,ind=0,opt=3):
	if globalGoalTest(tile_list,n)==1:
		return 0,[]
	if opt==4:
		m.penup()
		m.speed(0)
		m.goto((1-ind)*(-1)*x//6+ind*x//6+x//60,y//2-y//40)
		m.speed(1)
		m.shape("turtle")
		m.pendown()
		m.pencolor("blue")
	no_nodes=0
	tile_list1=tile_list
	res=[]
	temp=[[],[],[],[]]
	temp2=[[0,0],[1,0],[2,0],[3,0]]
	x1=0
	y1=0
	pathlen=0
	total_mem=0
	total_path=[[0,0]]
	while True:
		if globalGoalTest(tile_list1,n)==1:
				break
		res=bfs(tile_list1,n,ind,x1,y1,no_nodes,total_mem)

		x1=res[0][0]
		y1=res[0][1]
		total_mem+=res[2]
		path=res[0][2]
		total_path+=path
		pathlen+=len(path)
		no_nodes+=res[1]
		for i in path+[[x1,y1]]:
			if tile_list1[i[0]][i[1]]==1:
				tile_list1[i[0]][i[1]]=0
				# cleanDirt(x,y,i[0],i[1],2)
			if opt==4:
				m.goto((1-ind)*(-1)*x//6+ind*x//6+x//60+i[1]*x//30,y//2-y//40-i[0]*y//20)
	if res[0]==0:
		ans=[[0,0]]
	else:
		ans=res[0][2]
		
	sizeOfNode=sys.getsizeof(res[0])
	if len(ans)>0:
		extra_path=findNearestRest(ans[-1],n)
	elif len(ans)==0:
		extra_path=findNearestRest([0,0],n)
	if len(extra_path)>0:
		total_mem+=(len(extra_path)*sys.getsizeof(extra_path[0]))
	total_path+=extra_path
	ans=extra_path
	pathlen+=len(ans)
	no_nodes+=len(ans)
	cost=n*n*p//100+2*pathlen
	if opt==3:
		print("Action Path for T2(h1) is ")
		for i in total_path:
			print(i[0],i[1])
		print("cost(T2(h1))= ",cost)
	for i in ans:
		if tile_list1[i[0]][i[1]]==1:
			tile_list1[i[0]][i[1]]=0
			# cleanDirt(x,y,i[0],i[1],2)
		if opt==4:
			m.goto((1-ind)*(-1)*x//6+ind*x//6+x//60+i[1]*x//30,y//2-y//40-i[0]*y//20)
	if opt==4:
		T2_1_writer(x,y,p,n,no_nodes,cost,sizeOfNode,total_mem)
	return cost,total_path

def bottom_child(state,n,l,count):
	if state[0]<n-1 :
		l.append([state[0]+1,state[1],state[2]+[[state[0]+1,state[1]]]])
		count+=1
	return [l,count]
def right_child(state,n,l,count):
	if state[1]<n-1:
		l.append([state[0],state[1]+1,state[2]+[[state[0],state[1]+1]]])
		count+=1
	return [l,count]
def top_child(state,n,l,count):
	if state[0]>0:
		l.append([state[0]-1,state[1],state[2]+[[state[0]-1,state[1]]]])
		count+=1
	return [l,count]
def left_child(state,n,l,count):
	if state[1]>0:
		l.append([state[0],state[1]-1,state[2]+[[state[0],state[1]-1]]])
		count+=1
	return [l,count]

def chilGenerator_bfs(state,n,tile_list):
	l=[]
	count=0
	if state[1]>0 and tile_list[state[0]][state[1]-1]==1:
		l,count=left_child(state,n,l,count)
		l,count=top_child(state,n,l,count)
		l,count=right_child(state,n,l,count)
		l,count=bottom_child(state,n,l,count)
	elif state[0]>0 and tile_list[state[0]-1][state[1]]==1:
		l,count=top_child(state,n,l,count)
		l,count=left_child(state,n,l,count)
		l,count=right_child(state,n,l,count)
		l,count=bottom_child(state,n,l,count)
	elif state[1]<n-1 and tile_list[state[0]][state[1]+1]==1:
		l,count=right_child(state,n,l,count)
		l,count=left_child(state,n,l,count)
		l,count=top_child(state,n,l,count)
		l,count=bottom_child(state,n,l,count)
	elif state[0]<n-1 and tile_list[state[0]+1][state[1]]==1:
		l,count=bottom_child(state,n,l,count)
		l,count=left_child(state,n,l,count)
		l,count=top_child(state,n,l,count)
		l,count=right_child(state,n,l,count)
	elif state[1]<n-1 and ((state[0]>0 and tile_list[state[0]-1][state[1]+1]==1) or (state[0]<n-1 and tile_list[state[0]+1][state[1]+1]))==1:
		l,count=right_child(state,n,l,count)
		l,count=left_child(state,n,l,count)
		l,count=top_child(state,n,l,count)
		l,count=bottom_child(state,n,l,count)
	elif state[1]>0 and ((state[0]>0 and tile_list[state[0]-1][state[1]-1]==1) or (state[0]<n-1 and tile_list[state[0]+1][state[1]-1]==1)):
		l,count=left_child(state,n,l,count)
		l,count=bottom_child(state,n,l,count)
		l,count=right_child(state,n,l,count)
		l,count=top_child(state,n,l,count)
	else:
		l,count=left_child(state,n,l,count)
		l,count=top_child(state,n,l,count)
		l,count=right_child(state,n,l,count)
		l,count=bottom_child(state,n,l,count)
	k=0
	for i in range(count):
		for j in state[2]:
			if l[k][0]==j[0] and l[k][1]==j[1]:
				l.pop(k)
				k-=1
				break
		k+=1
	return l