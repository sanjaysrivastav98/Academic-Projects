#2015A7PS0102P K S Sanjay Srivastav
from __future__ import print_function
import random,sys

def printRoom(tile_list,n):
	for i in range(n):
		for j in range(n):
			print(tile_list[i][j],end=" ")
		print()

def dirtGenerator(p,n):
	tile_list=[]
	randlist=[]
	for i in range(n):
		tile_list.append([])
		for j in range(n):
			tile_list[i].append(0)
	try:
		randlist=random.sample(range(0,n*n),n*n*p//100)
	except ValueError:
		print('Sample size exceeded population size. ')
	for i in range(n*n*p//100):
		tile_list[randlist[i]//n][randlist[i]%n]=1
	return tile_list






		





