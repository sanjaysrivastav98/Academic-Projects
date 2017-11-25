#2015A7PS0102P K S Sanjay Srivastav
from __future__ import print_function
from dirtGenerator import dirtGenerator,printRoom
from turtle import *
from GUI import UI_generator,T1_writer,cleanDirt
import copy,turtle,sys

def globalGoalTest(state,n):
	for i in range(n):
		for j in range(n):
			if state[i][j]==1:
				return 0
	return 1

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
	ex=copy.deepcopy(explored)
	flag=0
	for i in range(n):
		for j in range(n):
			if tile_list[i][j]==1:
				flag=0
				for k in ex:
					if k[0]==i and k[1]==j:
						ex.remove(k)
						flag=1
						break
				if flag==0:
					return 0
	return 1

def idfs(max_depth,n,tile_list,ind,no_nodes,total_mem):
	explored=[]
	Stack=[]
	max_stack=0
	Stack.append([0,0,max_depth])
	total_mem+=sys.getsizeof(Stack[-1])
	while(len(Stack)>0):
		if len(Stack)>max_stack:
			max_stack=len(Stack)
		temp=Stack.pop()
		total_mem-=sys.getsizeof(temp)
		no_nodes+=1
		ex=explored[:]
		k=0
		for j in range(len(ex)):
			if len(explored)>0 and ex[j][2]<=temp[2]:
				t=explored.pop(k)
				total_mem-=sys.getsizeof(t)
				no_nodes+=1
				k-=1
			k+=1
		explored.append(temp)
		total_mem+=sys.getsizeof(explored[-1])
		if temp[2]==0:
			if goalTest(explored,tile_list,n)==1:
				if len(Stack)>max_stack:
					max_stack=len(Stack)
				return explored,no_nodes,total_mem,max_stack
		else:
			chil=getchil(temp,explored,n)
			if len(chil)>0:
				for i in range(len(chil)-1,-1,-1):
					Stack.append(chil[i])
					total_mem+=sys.getsizeof(Stack[-1])
	return 0,no_nodes,total_mem,max_stack


	# tile_list_temp=copy.deepcopy(tile_list)
	# for i in temp[2]:
	# 	if tile_list_temp[i[0]][i[1]]==1:
	# 		tile_list_temp[i[0]][i[1]]=0

	# for i in range(n):
	# 	for j in range(n):
	# 		if tile_list_temp[i][j]==1:
	# 			return 0
	# return 1



def findNearestRest(explored,n):
	path=[]

	x=explored[0]
	y=explored[1]
	if x<n//2:
		if y<n//2:
			i=x
			j=y
			while(i>0):
				i-=1
				path.append([i,j,0])
			while(j>0):
				j-=1
				path.append([i,j,0])

		else:
			i=x
			j=y
			while(i>0):
				i-=1
				path.append([i,j,0])
			while(j<n-1):
				j+=1
				path.append([i,j,0])
	else:
		if y<=n//2:
			i=x
			j=y
			while(i<n-1):
				i+=1
				path.append([i,j,0])
			while(j>0):
				j-=1
				path.append([i,j,0])
		else:
			i=x
			j=y
			while(i<n-1):
				i+=1
				path.append([i,j,0])
			while(j<n-1):
				j+=1
				path.append([i,j,0])
	return path


def idfs_caller(m,x,y,tile_list,p,n,ind=0,opt=2):
	if globalGoalTest(tile_list,n)==1:
		return 0,[]
	if opt==4:
		m.penup()
		m.speed(0)
		m.goto(-1*x//6+x//60,y//2-y//40)
		m.shape("turtle")
		m.pendown()
		m.pencolor("red")
	tile_list1=tile_list
	res=[]
	no_nodes=0
	total_mem=0
	max_stack=0
	for i in range(p*n*n//100,n*n):
		res=idfs(i,n,tile_list1,ind,no_nodes,total_mem)
		no_nodes+=res[1]
		total_mem+=res[2]
		if res[3]>max_stack:
			max_stack=res[3]
		if res[0]!=0:
			break
	if len(res)==1:
		sizeOfNode=sys.getsizeof(res[0][0])
		extra_path=findNearestRest(res[0][0],n)
	else:
		sizeOfNode=sys.getsizeof(res[0][-1])
		extra_path=findNearestRest(res[0][-1],n)
	no_nodes+=len(extra_path)
	if len(extra_path)>0:
		total_mem+=(len(extra_path)*sys.getsizeof(extra_path[0]))
	cost=p*n*n//100+2*len(res[0])+2*len(extra_path)-2
	if opt==4:
		T1_writer(x,y,p,n,no_nodes,cost,sizeOfNode,total_mem,max_stack)
	path=res[0]+extra_path
	if opt==2:
		print("Action Path for T1 is ")
	for i in path:
		if opt==2:
			print(i[0],i[1])
		if opt==4:
			if tile_list1[i[0]][i[1]]==1:
				tile_list1[i[0]][i[1]]=0
				cleanDirt(x,y,i[0],i[1],2)
			m.goto(-1*x//6+x//60+i[1]*x//30,y//2-y//40-i[0]*y//20)
	if opt==2:
		print("cost(T1)= ",cost)
	return cost,path



