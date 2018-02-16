#2015A7PS0102P K S Sanjay Srivastav
from GUI import writeAns,writemb,writemb1,write_error,write_exp,getCornerCoors,clearUI,close_main_window,drawBottom,processing,drawOutline,draw_box
from turtle import *
import turtle,time
import os.path

class node:
	def __init__(self,name,prob_list,pars):
		self.name=name
		self.pars=pars
		self.prob_list=prob_list
		self.children=[]
	def __repr__(self):
		temp=""
		for i in self.pars:
			temp+=i.name+" "
		temp2=""
		for i in self.children:
			temp2+=i.name+" "
		return self.name+" : Pars= "+temp+" Childs: "+temp2
	def addPar(self,par):
		flag=0
		for i in self.pars:
			if i.name==par.name:
				flag=1
		if flag==0:
			self.pars.append(par)
	def addChild(self,child):
		flag=0
		for i in self.children:
			if i.name==child.name:
				flag=1
		if flag==0:
			self.children.append(child)



class BayesianNetwork:
	def __init__(self,node_list=[]):
		self.node_list=node_list
	def add_Node(self,node):
		self.node_list.append(node)
	def getNode(self,name):
		for i in self.node_list:
			if i.name==name:
				return i
		return -1
	def __repr__(self):
		return str(self.node_list)

class MarkovBlanket:
	def __init__(self,node,pars=[],chils=[],chilpars=[]):
		self.node=node
		self.pars=pars
		self.chils=chils
		self.chilpars=chilpars
	def setPars(self,par_list):
		self.pars=par_list
	def setChildren(self,child_list):
		self.chils=child_list
	def setChilPars(self,chilpar_list):
		self.chilpars=chilpar_list
	def getMarkovBlanket(self):
		temp=[node.name]
		for i in self.pars:
			temp.append(i.name)
		for i in self.chils:
			temp.append(i.name)
		for i in self.chilpars:
			temp.append(i.name)
		return temp

	def __repr__(self):
		temp="Node: "+self.node.name+","
		if len(self.pars)>0:
			temp+=" Parents= "
		else:
			temp+=" No Parents"
		for i in range(len(self.pars)-1):
			temp+=self.pars[i].name+", "
		if(len(self.pars)>0):
			temp+=self.pars[-1].name
		if(len(self.chils)>0):
			temp+="\nChildren= "
		else:
			temp+="\nNo Children"
		for i in range(len(self.chils)-1):
			temp+=self.chils[i].name+", "
		if(len(self.chils)>0):
			temp+=self.chils[-1].name
			if(len(self.chilpars)>0):
				temp+="\nParents of Children= "
			else:
				temp+="\nNo Parents of Children"
			for i in range(len(self.chilpars)-1):
				temp+=self.chilpars[i].name+", "
			if(len(self.chilpars)>0):
				temp+=self.chilpars[-1].name
			temp+="\n"
		return temp

class expression:
	def __init__(self,query_vars,condition_vars):
		self.query_vars=query_vars
		self.condition_vars=condition_vars
	def __repr__(self):
		temp="P("
		for i in range(len(self.query_vars)-1):
			temp+=str(self.query_vars[i])+","
		temp+=str(self.query_vars[-1])
		if len(self.condition_vars)>0:
			temp+="|"
		for i in range(len(self.condition_vars)-1):
			temp+=str(self.condition_vars[i])+","
		if len(self.condition_vars)>0:
			temp+=str(self.condition_vars[-1])
		temp+=")"
		return temp

class OnClick:
	def __init__(self,turt,bayes_net,l):
		self.t=turt
		self.bayes_net=bayes_net
		self.l=l
		self.q_list=[]
		self.c_list=[]
		self.newQ=False
		self.endClick=False

	def click(self,x,y):
		if self.newQ:
			self.newQueryClick(x,y)
		if x>=220 and x<=380 and y>=-300 and y<=-270:
			if len(self.q_list)==0:
				write_error(self.t)
			else:
				processing(self.t,0)
				exp=createExpression(self.q_list,self.c_list)
				ans=computeProbability(self.bayes_net,exp)
				for i in self.q_list:
					if i[0]=="~":
						j=i[1]
					else:
						j=i
					writemb(computeMarkovBlanket(self.bayes_net,j))
				for i in self.c_list:
					if i[0]=="~":
						j=i[1]
					else:
						j=i
					writemb1(computeMarkovBlanket(self.bayes_net,j))
				writeAns(self.t,ans)
				self.newQ=True	
		if not self.newQ:
			x,y,i=getCornerCoors(x,y,len(self.bayes_net.node_list))
			if x==-300 and len(self.q_list)<10 and self.l[i] not in self.q_list and self.l[i] not in self.c_list and "~"+self.l[i] not in self.q_list and "~"+self.l[i] not in self.c_list:
				self.q_list.append(self.l[i])
				draw_box(self.t,self.l[i],x,y,1,0)
			elif x==-240 and len(self.q_list)<10 and self.l[i] not in self.q_list and self.l[i] not in self.c_list and "~"+self.l[i] not in self.q_list and "~"+self.l[i] not in self.c_list:
				self.q_list.append("~"+self.l[i])
				draw_box(self.t,self.l[i],x,y,0,0)
			elif x==100 and len(self.c_list)<10 and self.l[i] not in self.q_list and self.l[i] not in self.c_list and "~"+self.l[i] not in self.q_list and "~"+self.l[i] not in self.c_list:
				self.c_list.append(self.l[i])
				draw_box(self.t,self.l[i],x,y,1,0)
			elif x==160 and len(self.c_list)<10 and self.l[i] not in self.q_list and self.l[i] not in self.c_list and "~"+self.l[i] not in self.q_list and "~"+self.l[i] not in self.c_list:
				self.c_list.append("~"+self.l[i])
				draw_box(self.t,self.l[i],x,y,0,0)
	def newQueryClick(self,x,y):
		if x>=230 and x<=330 and y>=-260 and y<=-230:
			turtle.onscreenclick(None)
			newQuery(self.t,self.bayes_net)
			self.q_list=[]
			self.c_list=[]
			self.newQ=False


def createBayesianNetwork(name):
	f=open(name,"r")
	temp=f.read().split('\n')
	cpvars=[]
	bayes_net=BayesianNetwork()
	for i in temp:
		if i=='$$':
			break
		temp2=i.split(' >> ')
		parlist=temp2[1][1:-1].split(', ')
		if parlist==['']:
			parlist=[]
		cpvars.append(parlist)
		temp3=[float(x) for x in temp2[2].split(' ')]
		A=node(temp2[0],temp3,[])
		bayes_net.add_Node(A)
	for i in range(len(cpvars)):
		for j in cpvars[i]:
			bayes_net.node_list[i].addPar(bayes_net.getNode(j))
			bayes_net.getNode(j).addChild(bayes_net.node_list[i])
	return bayes_net

def computeMarkovBlanket(bayes_net,name):
	node=bayes_net.getNode(name)
	markov_blanket=MarkovBlanket(node)
	par_list=[]
	for i in node.pars:
		par_list.append(i)
	markov_blanket.setPars(par_list)
	chil=[]
	for i in bayes_net.node_list:
		flag=0
		for j in i.pars:
			if j.name==node.name:
				flag=1
				break
		if flag==1:
			chil.append(i)
	markov_blanket.setChildren(chil)
	chil_pars=[]
	for i in chil:
		for j in i.pars:
			flag=0
			for k in chil:
				if j.name==k.name:
					flag=1
					break
			if flag==0 and j.name!=node.name:
				chil_pars.append(j)
	markov_blanket.setChilPars(chil_pars)
	return markov_blanket

def createExpression(query_vars,condition_vars):
	exp=expression(query_vars,condition_vars)
	write_exp(exp)
	return exp

def getEleToAdd(bayes_net,lis):
	temp=[]
	lis2=[]
	for i in lis:
		lis2.append(i)
	for i in lis2:
		if i[0]=='~':
			j=i[1]
		else:
			j=i
		temp2=computeMarkovBlanket(bayes_net,j)
		temp+=temp2.pars
		temp+=temp2.chils
		temp+=temp2.chilpars
		temp=list(set(temp))
		for j in temp:
			if j.name not in lis2 and "~"+j.name not in lis2:
				lis2.append(j.name)
	temp2=[]
	for i in lis2:
		if i in lis or "~"+i in lis:
			continue
		else:
			temp2.append(i)
	return allposs(temp2)

def allposs(lis):
	if len(lis)==0:
		return []
	if len(lis)==1:
		return [[lis[0]],["~"+lis[0]]]
	temp=allposs(lis[:-1])
	return [i+[j] for i in temp for j in [lis[-1],"~"+lis[-1]]]

def allElementsProb(bayes_net,lis):
	newEle=getEleToAdd(bayes_net,lis)
	allEle=[]
	for i in newEle:
		allEle.append(lis+i)
	if len(newEle)==0:
		allEle.append(lis)
	s=0
	for i in allEle:
		s+=jointProb(bayes_net,i,i,1.0)
	return s

def jointProb(bayes_net,temp_lis,lis,acc):
	if len(lis)==0:
		return 1
	if lis[0][0]=="~":
		j=lis[0][1]
	else:
		j=lis[0][0]
	node=bayes_net.getNode(j)
	temp=0
	for i in node.pars:
		if i.name in temp_lis:
			temp=2*temp+1
		elif "~"+i.name in temp_lis:
			temp=2*temp+0

	if len(lis)==1:
		if lis[0][0]=='~':
			return acc*(1-node.prob_list[temp])
		else:
			return acc*node.prob_list[temp]
	if lis[0][0]=='~':
		return jointProb(bayes_net,temp_lis,lis[1:],acc*(1-node.prob_list[temp]))
	else:
		return jointProb(bayes_net,temp_lis,lis[1:],acc*node.prob_list[temp])

def computeProbability(bayes_net,expression):
	num=allElementsProb(bayes_net,expression.query_vars+expression.condition_vars)
	den=allElementsProb(bayes_net,expression.condition_vars)
	if den==0:
		return num
	return num/den

def mainGUI(bayes_net):
	turtle.setup(900,700)
	GUI(bayes_net)
	close_main_window()

def GUI(bayes_net):
	t=Turtle()
	t.ht()
	t.pu()
	t.speed(0)
	turtle.onscreenclick(None)
	drawOutline(t)
	count=0
	xcor=-300
	ycor=300
	l=[]
	for i in bayes_net.node_list:
		l.append(i.name)
	l=sorted(l)
	for i in l:
		draw_box(t,i,xcor,ycor,1,1)
		xcor+=60
		draw_box(t,i,xcor,ycor,0,1)
		xcor=100
		draw_box(t,i,xcor,ycor,1,1)
		xcor+=60
		draw_box(t,i,xcor,ycor,0,1)
		xcor=-300
		ycor-=33
	drawBottom(t)
	cl=OnClick(t,bayes_net,l)
	turtle.onscreenclick(cl.click)

def newQuery(t,bayes_net):
	clearUI(t)
	GUI(bayes_net)

