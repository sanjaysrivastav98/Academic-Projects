# 2015A7PS0102P K S Sanjay Srivastav

from __future__ import print_function
from constraints import Laboratory_constraint_1,Laboratory_constraint_2,Tutorial_constraint_3,Disciplinary_constraint_4,General_constraint_5,Lecture_constraint_6,Laboratory_constraint_7,Professor_constraint_8,Professor_constraint_9,Student_constraint_10,Professor_constraint_11
from preprocessing import ltp_generator,domain,ltp,CSP,generate_package,Constraint_Graph
from nestedfor import func
import copy,sys

def DFS_BT(CSP,variable_list,constraint_graph):
	if len(variable_list)==len(ltp):
		return True,variable_list
	course="C_"
	if len(variable_list)>=9:
		course+=str(len(variable_list)+1)
	else:
		course+="0"+str(len(variable_list)+1)
	allposs_l=func(int(ltp[len(variable_list)][0]),course)
	allposs_t=func(int(ltp[len(variable_list)][1]),course)
	if int(ltp[len(variable_list)][2])==3:
		allposs_p1=[[16,17,18],[26,27,28],[36,37,38],[46,47,48],[56,57,58]]
		allposs_p2=[[16,17,18],[26,27,28],[36,37,38],[46,47,48],[56,57,58]]
	elif int(ltp[len(variable_list)][2])==2:
		allposs_p1=[[16,17],[17,18],[26,27],[27,28],[36,37],[37,38],[46,47],[47,48],[56,57],[57,58]]
		allposs_p2=[[16,17],[17,18],[26,27],[27,28],[36,37],[37,38],[46,47],[47,48],[56,57],[57,58]]
	elif int(ltp[len(variable_list)][2])==1:
		allposs_p1=[[16],[17],[18],[26],[27],[28],[36],[37],[38],[46],[47],[48],[56],[57],[58]]
		allposs_p2=[[16],[17],[18],[26],[27],[28],[36],[37],[38],[46],[47],[48],[56],[57],[58]]
	else:
		allposs_p1=[[]]
		allposs_p2=[[]]
	allposs_p=[]
	# return
	for i in allposs_p1:
		for j in allposs_p2:
			if i!=j:
				allposs_p.append([i,j])
	

	assigned=[]
	CG=constraint_graph
	
	for i in allposs_l:
		for j in allposs_t:
			for k in allposs_p:
				variable_list.append([i,j,k])
				from_node=variable_list[-1]
				ind=len(variable_list)-1
				from_node_all=variable_list
				if not Laboratory_constraint_1(CSP,CG,from_node):
					# print("inside 1")
					variable_list.pop(-1)
					continue
				if not Laboratory_constraint_2(CSP,CG,from_node):
					# print("inside 2")
					variable_list.pop(-1)
					continue
				if not Tutorial_constraint_3(CSP,CG,from_node):
					# print("inside 3")
					variable_list.pop(-1)
					continue
				if not Disciplinary_constraint_4(CSP,CG,from_node_all,ind):
					# print("inside 4")
					variable_list.pop(-1)
					continue
				if not General_constraint_5(CSP,CG,from_node_all,ind):
					# print("inside 5")
					variable_list.pop(-1)
					continue
				if not Lecture_constraint_6(CSP,CG,from_node):
					# print("inside 6")
					variable_list.pop(-1)
					continue
				if not Laboratory_constraint_7(CSP,CG,from_node_all,ind):
					# print("inside 7")
					variable_list.pop(-1)
					continue
				if not Professor_constraint_8(CSP,CG,from_node_all,ind):
					# print("inside 8")
					variable_list.pop(-1)
					continue
				if not Professor_constraint_9(CSP,CG,from_node_all,ind):
					# print("inside 9")
					variable_list.pop(-1)
					continue
				if not Student_constraint_10(CSP,CG,from_node_all,ind):
					# print("inside 10")
					variable_list.pop(-1)
					continue
				if not Professor_constraint_11(CSP,CG,from_node_all,ind):
					# print("inside 11")
					variable_list.pop(-1)
					continue

				res=DFS_BT(CSP,variable_list,constraint_graph)
				if res[0]:
					return True,res[1]
				variable_list.pop(-1)
	return False,variable_list
	
def DFS_BT_CP(CSP,variable_list,constraint_graph):
	# print(variable_list)
	if len(variable_list)==len(ltp):
		return True,variable_list
	course="C_"
	if len(variable_list)>=9:
		course+=str(len(variable_list)+1)
	else:
		course+="0"+str(len(variable_list)+1)
	allposs_l=func(int(ltp[len(variable_list)][0]),course)
	allposs_t=func(int(ltp[len(variable_list)][1]),course)
	if int(ltp[len(variable_list)][2])==3:
		allposs_p1=[[16,17,18],[26,27,28],[36,37,38],[46,47,48],[56,57,58]]
		allposs_p2=[[16,17,18],[26,27,28],[36,37,38],[46,47,48],[56,57,58]]
	elif int(ltp[len(variable_list)][2])==2:
		allposs_p1=[[16,17],[17,18],[26,27],[27,28],[36,37],[37,38],[46,47],[47,48],[56,57],[57,58]]
		allposs_p2=[[16,17],[17,18],[26,27],[27,28],[36,37],[37,38],[46,47],[47,48],[56,57],[57,58]]
	elif int(ltp[len(variable_list)][2])==1:
		allposs_p1=[[16],[17],[18],[26],[27],[28],[36],[37],[38],[46],[47],[48],[56],[57],[58]]
		allposs_p2=[[16],[17],[18],[26],[27],[28],[36],[37],[38],[46],[47],[48],[56],[57],[58]]
	else:
		allposs_p1=[[]]
		allposs_p2=[[]]
	allposs_p=[]
	for i in allposs_p1:
		for j in allposs_p2:
			if i!=j:
				allposs_p.append([i,j])
	assigned=[]
	CG=constraint_graph
	for i in allposs_l:
		for j in allposs_t:
			for k in allposs_p:
				variable_list.append([i,j,k])
				from_node=variable_list[-1]
				ind=len(variable_list)-1
				from_node_all=variable_list
				if not Laboratory_constraint_1(CSP,CG,from_node):
					# print("inside 1")
					variable_list.pop(-1)
					continue
				if not Laboratory_constraint_2(CSP,CG,from_node):
					# print("inside 2")
					variable_list.pop(-1)
					continue
				if not Tutorial_constraint_3(CSP,CG,from_node):
					# print("inside 3")
					variable_list.pop(-1)
					continue
				if not Disciplinary_constraint_4(CSP,CG,from_node_all,ind):
					# print("inside 4")
					variable_list.pop(-1)
					continue
				if not General_constraint_5(CSP,CG,from_node_all,ind):
					# print("inside 5")
					variable_list.pop(-1)
					continue
				if not Lecture_constraint_6(CSP,CG,from_node):
					# print("inside 6")
					variable_list.pop(-1)
					continue
				if not Laboratory_constraint_7(CSP,CG,from_node_all,ind):
					# print("inside 7")
					variable_list.pop(-1)
					continue
				if not Professor_constraint_8(CSP,CG,from_node_all,ind):
					# print("inside 8")
					variable_list.pop(-1)
					continue
				if not Professor_constraint_9(CSP,CG,from_node_all,ind):
					# print("inside 9")
					variable_list.pop(-1)
					continue
				if not Student_constraint_10(CSP,CG,from_node_all,ind):
					# print("inside 10")
					variable_list.pop(-1)
					continue
				if not Professor_constraint_11(CSP,CG,from_node_all,ind):
					# print("inside 11")
					variable_list.pop(-1)
					continue

				temp_list_i=i+j+k[0]+k[1]
				clist1=[]
				clist2=[]
				course="C_"
				if len(variable_list)>9:
					course+=str(len(variable_list))
				else:
					course+="0"+str(len(variable_list))
				for l in CG[0][course]:
					for m in range(len(temp_list_i)):
						if temp_list_i[m] in domain[l]:
							domain[l].remove(temp_list_i[m])
							clist1.append(m)
				for l in CG[1][course]:
					for m in range(len(temp_list_i)):
						if temp_list_i[m] in domain[l]:
							domain[l].remove(temp_list_i[m])
							clist2.append(m)

				res=DFS_BT_CP(CSP,variable_list,constraint_graph)
				print(res)
				if res[0]:
					return True,res[1]
				for l in CG[0][course]:
					for m in clist1:
						domain[l]+=[temp_list_i[m]]
				for l in CG[1][course]:
					for m in clist2:
						domain[l]+=[temp_list_i[m]]
				variable_list.pop(-1)
	return False,variable_list