#2015A7PS0102P K S Sanjay Srivastav

from __future__ import print_function
from preprocessing import ltp_generator,ltp,CSP,programA,programB,programC,prof_dictionary

def Laboratory_constraint_1(CSP,CG,from_node):
	if len(from_node)>0:
		if len(from_node[2])>0:
			for batch in from_node[2]:
				for j in batch:
					if j%10<6:
						return False
	return True


def Laboratory_constraint_2(CSP,CG,from_node):
	if len(from_node)>0:
		if len(from_node[2])>0:
			for batch in from_node[2]:
				if len(batch)>0:
					batch.sort()
					temp=batch[0]
					for j in range(1,len(batch)):
						if batch[j]-temp!=1:
							return False
						temp=batch[j]
	return True


def Tutorial_constraint_3(CSP,CG,from_node):
	if len(from_node)>0:
		if len(from_node[0])>0:
			tens_l=from_node[0][0]//10
			for i in range(len(from_node[0])):
				tens_l=from_node[0][i]//10
				for j in range(len(from_node[1])):
					tens_t=from_node[1][j]//10
					if tens_t==tens_l:
						return False
	return True

def Disciplinary_constraint_4(CSP,CG,from_node_all,ind):
	DClist_A=programA["DC"]
	DClist_B=programB["DC"]
	DClist_C=programC["DC"]
	temp="C_"
	if ind>=9:
		temp+=str(ind+1)
	else:
		temp+="0"+str(ind+1)
	temp_list_i=from_node_all[ind]
	temp_batch_list_i=[]
	for batch in temp_list_i[2]:
		temp_batch_list_i+=batch
	temp_list2_i=temp_list_i[0]+temp_list_i[1]+temp_batch_list_i
	# print("temp" ,temp_list2_i)
	if temp in DClist_A:
		for i in temp_list2_i:
			tens_i=i//10
			ones_i=i%10
			for j in range(len(DClist_A)):
				if j ==ind:
					continue
				if int(DClist_A[j][2:])<len(from_node_all):
					temp_list=from_node_all[int(DClist_A[j][2:])-1]
					temp_batch_list=[]
					for batch in temp_list[2]:
						temp_batch_list+=batch
					temp_list2=temp_list[0]+temp_list[1]+temp_batch_list
					for k in temp_list2:
						tens_j=k//10
						ones_j=k%10
						if tens_i==tens_j and (ones_i-ones_j==1 or ones_j-ones_i==1) :
							return False
	if temp in DClist_B:
		for i in temp_list2_i:
			tens_i=i//10
			ones_i=i%10
			for j in range(len(DClist_B)):
				if j==ind:
					continue
				if int(DClist_B[j][2:])<len(from_node_all):
					temp_list=from_node_all[int(DClist_B[j][2:])-1]
					temp_batch_list=[]
					for batch in temp_list[2]:
						temp_batch_list+=batch
					temp_list2=temp_list[0]+temp_list[1]+temp_batch_list
					for k in temp_list2:
						tens_j=k//10
						ones_j=k%10
						if tens_i==tens_j and (ones_i-ones_j==1 or ones_j-ones_i==1) :
							return False
	if temp in DClist_C:
		for i in temp_list2_i:
			tens_i=i//10
			ones_i=i%10
			for j in range(len(DClist_C)):
				if j==ind:
					continue
				if int(DClist_C[j][2:])<len(from_node_all):
					temp_list=from_node_all[int(DClist_C[j][2:])-1]
					temp_batch_list=[]
					for batch in temp_list[2]:
						temp_batch_list+=batch
					temp_list2=temp_list[0]+temp_list[1]+temp_batch_list
					for k in temp_list2:
						tens_j=k//10
						ones_j=k%10
						if tens_i==tens_j and (ones_i-ones_j==1 or ones_j-ones_i==1) :
							return False
	return True	


def General_constraint_5(CSP,CG,from_node_all,ind):
	GE_list=programA["GE"]+programB["GE"]+programC["GE"]
	temp_list=from_node_all[ind]
	temp="C_"
	if ind>=9:
		temp+=str(ind+1)
	else:
		temp+="0"+str(ind+1)
	temp_list_i=from_node_all[ind]
	temp_batch_list=[]
	for batch in temp_list_i[2]:
		temp_batch_list+=batch
	temp_list2_i=temp_list_i[0]+temp_list_i[1]+temp_batch_list
	if temp in GE_list:
		for i in temp_list2_i:
			tens_i=i//10
			for j in range(len(GE_list)):
				if j==ind:
					continue
				if int(GE_list[j][2:])<len(from_node_all):
					temp_list=from_node_all[int(GE_list[j][2:])-1]
					temp_batch_list=[]
					for batch in temp_list[2]:
						temp_batch_list+=batch
					temp_list2=temp_list[0]+temp_list[1]+temp_batch_list
					for k in temp_list2:
						tens_j=k//10
						if tens_j==tens_i:
							return False
	return True	

def Lecture_constraint_6(CSP,CG,from_node):
	if len(from_node)>0:
		lis=from_node[0]
		tens_lis=[]
		for i in lis:
			tens_lis.append(i//10)
		n=len(tens_lis)
		m=len(list(set(tens_lis)))
		if n==m:
			return True
	return False


def Laboratory_constraint_7(CSP,CG,from_node_all,ind):
	if len(from_node_all[ind])>0:
		if from_node_all[ind][2]>0 :
			for i in from_node_all[ind][2]:
				if len(i)!=ltp[ind][2]:
					return False
	return True


def Professor_constraint_8(CSP,CG,from_node_all,ind):
	for i in prof_dictionary["Prof-1"]:
		if int(i[2:])==ind:
			if from_node_all[ind][2]>0:
				batch=[]
				for j in range(len(from_node_all[ind][2])):
					batch+=from_node_all[ind][2][j]
			templist=from_node_all[ind][0]+from_node_all[ind][1]+batch
			for j in templist:
				ones=j%10
				if ones!=2 and ones!=1:
					return False
	for i in prof_dictionary["Prof-4"]:
		if int(i[2:])==ind:
			if from_node_all[ind][2]>0:
				batch=[]
				for j in range(len(from_node_all[ind][2])):
					batch+=from_node_all[ind][2][j]
			templist=from_node_all[ind][0]+from_node_all[ind][1]+batch
			for j in templist:
				tens=j//10
				if tens==4:
					return False
	return True


def Professor_constraint_9(CSP,CG,from_node_all,ind):
	for j in prof_dictionary:
		for i in prof_dictionary[j]:
			if int(i[2:])==ind:
				if from_node_all[ind][2]>0:
					batch=[]
					for j in range(len(from_node_all[ind][2])):
						batch+=from_node_all[ind][2][j]
				templist=from_node_all[ind][0]+from_node_all[ind][1]+batch
				for j in temp_list:
					for k in temp_list:
						if j-k==1:
							return False
	return True



def Student_constraint_10(CSP,CG,from_node_all,ind):
	batch=[]
	for j in range(len(from_node_all[ind][2])):
		batch+=from_node_all[ind][2][j]
	temp_list_A=from_node_all[ind][0]+from_node_all[ind][1]+batch
	n=len(temp_list_A)
	m=len(list(set(temp_list_A)))
	if m!=n:
		return False
	temp="C_"
	if ind>=9:
		temp+=str(ind+1)
	else:
		temp+="0"+str(ind+1)
	for i in CG[0][temp]:
		batch=[]
		if len(from_node_all)>int(i[2:]):
			for j in range(len(from_node_all[int(i[2:])][2])):
				batch+=from_node_all[int(i[2:])][2][j]
			temp_list_B=from_node_all[int(i[2:])][j][0]+from_node_all[int(i[2:])][j][1]+batch
			for j in temp_list_A:
				for k in temp_list_B:
					if j==k:
						return False
	return True

	

def Professor_constraint_11(CSP,CG,from_node_all,ind):
	batch=[]
	for j in range(len(from_node_all[ind][2])):
		batch+=from_node_all[ind][2][j]
	temp_list_A=from_node_all[ind][0]+from_node_all[ind][1]+batch
	temp="C_"
	if ind>=9:
		temp+=str(ind+1)
	else:
		temp+="0"+str(ind+1)
	for i in CG[1][temp]:
		batch=[]
		if len(from_node_all)>int(i[2:]):
			for j in range(len(from_node_all[int(i[2:])][2])):
				batch+=from_node_all[int(i[2:])][2][j]
			temp_list_B=from_node_all[int(i[2:])][j][0]+from_node_all[int(i[2:])][j][1]+batch
			for j in temp_list_A:
				for k in temp_list_B:
					if j==k:
						return False
	return True

	