#2015A7PS0102P K S Sanjay Srivastav

from __future__ import print_function
import csv

def printf(diction):
	print("programA:")
	for i in diction["programA"]:
		print(i)
	print()
	print("programB:")
	for i in diction["programB"]:
		print(i)
	print()
	print("programC:")
	for i in diction["programC"]:
		print(i)
	print()
rowlist=[]
prof_dictionary={}
global programA
global programB
global programC
programA={"DE":[],"DC":[],"GE":[]}
programB={"DE":[],"DC":[],"GE":[]}
programC={"DE":[],"DC":[],"GE":[]}
def generate_package(testcasefile):
	program_Dictionary={
	"programA":[],"programB":[],"programC":[]
	}
	spamreader = csv.reader(testcasefile, delimiter=' ', quotechar='|')
	global programA
	global programB
	global programC
	for i in spamreader:
		i=', '.join(i)
		rowlist.append(i.split(','))
	
	j1=0
	for i in range(2,len(rowlist)):
		if rowlist[i][0]=="$PROF$":
			j1=i+2
			break
		if rowlist[i][1]!="NA":
			programA[rowlist[i][1]].append(rowlist[i][0])
		if rowlist[i][2]!="NA":
			programB[rowlist[i][2]].append(rowlist[i][0])
		if rowlist[i][3]!="NA":
			programC[rowlist[i][3]].append(rowlist[i][0])
	DC_list=[]
	DE_list=[]
	GE_list=[]
	for i in range(0,len(programA["DC"])-2):
		for j in range(i+1,len(programA["DC"])-1):
			for k in range(j+1,len(programA["DC"])):
				DC_list.append([programA["DC"][i],programA["DC"][j],programA["DC"][k]])
	for i in range(0,len(programA["DE"])-1):
		for j in range(i+1,len(programA["DE"])):
			DE_list.append([programA["DE"][i],programA["DE"][j]])
	for i in range(len(programA["GE"])):
		GE_list.append([programA["GE"][i]])
	for i in GE_list:
		for j in DE_list:
			for k in DC_list:
				program_Dictionary["programA"].append([k,j,i])

	DC_list=[]
	DE_list=[]
	GE_list=[]
	for i in range(0,len(programB["DC"])-2):
		for j in range(i+1,len(programB["DC"])-1):
			for k in range(j+1,len(programB["DC"])):
				DC_list.append([programB["DC"][i],programB["DC"][j],programB["DC"][k]])
	for i in range(0,len(programB["DE"])-1):
		for j in range(i+1,len(programB["DE"])):
			DE_list.append([programB["DE"][i],programB["DE"][j]])
	for i in range(len(programB["GE"])):
		GE_list.append([programB["GE"][i]])
	for i in GE_list:
		for j in DE_list:
			for k in DC_list:
				program_Dictionary["programB"].append([k,j,i])

	DC_list=[]
	DE_list=[]
	GE_list=[]
	for i in range(0,len(programC["DC"])-2):
		for j in range(i+1,len(programC["DC"])-1):
			for k in range(j+1,len(programC["DC"])):
				DC_list.append([programC["DC"][i],programC["DC"][j],programC["DC"][k]])
	for i in range(0,len(programC["DE"])-1):
		for j in range(i+1,len(programC["DE"])):
			DE_list.append([programC["DE"][i],programC["DE"][j]])
	for i in range(len(programC["GE"])):
		GE_list.append([programC["GE"][i]])
	for i in GE_list:
		for j in DE_list:
			for k in DC_list:
				program_Dictionary["programC"].append([k,j,i])

	global prof_dictionary
	for i in range(j1,len(rowlist)):
		for k in range(4):
			if rowlist[i][k+1]=="NA":
				break
			if rowlist[i][0] not in prof_dictionary:
				prof_dictionary[rowlist[i][0]]=[]
			prof_dictionary[rowlist[i][0]].append(rowlist[i][k+1])
			
	return program_Dictionary,prof_dictionary

global CSP
CSP=rowlist
global ltp
ltp=[]
def ltp_generator(CSP):
	global domain
	global ltp
	lis=[11,12,13,14,16,17,18,21,22,23,24,26,27,28,31,32,33,34,36,37,38,41,42,43,44,46,47,48,51,52,53,54,56,57,58,61,62,63,64]
	for i in range(2,len(rowlist)):
		if CSP[i][0]=="$PROF$":
			break
		ltp.append([int(CSP[i][4]),int(CSP[i][5]),int(CSP[i][6])])
		domain[CSP[i][0]]=lis
	# return ltp,domain

global domain

lis=[11,12,13,14,15,16,17,21,22,23,24,25,26,27,31,32,33,34,35,36,37,41,42,43,44,45,46,47,51,52,53,54,55,56,57,61,62,63,64]


domain={}
domain["C_01"]=[16,17,18,26,27,28]


def Constraint_Graph(package):
	program_Dictionary=package[0]
	prof_dictionary=package[1]
	adj_list={}
	adj_list2={}
	for i in program_Dictionary:
		for j in program_Dictionary[i]:
			temp_list=[]
			for k in j:
				for l in k:
					temp_list.append(l)
			for k in range(len(temp_list)-1):
				for l in range(k+1,len(temp_list)):
					if temp_list[k] not in adj_list:
						adj_list[temp_list[k]]=[]
					if temp_list[l] not in adj_list:
						adj_list[temp_list[l]]=[]
					if temp_list[l] not in adj_list[temp_list[k]]:
						adj_list[temp_list[k]].append(temp_list[l])
					if temp_list[k] not in adj_list[temp_list[l]]:
						adj_list[temp_list[l]].append(temp_list[k])
	for i in prof_dictionary:
		temp_list=[]
		for j in prof_dictionary[i]:
			temp_list.append(j)
		for k in range(len(temp_list)-1):
			for l in range(k+1,len(temp_list)):
				if temp_list[k] not in adj_list2:
					adj_list2[temp_list[k]]=[]
				if temp_list[l] not in adj_list2:
					adj_list2[temp_list[l]]=[]
				if temp_list[l] not in adj_list2[temp_list[k]]:
					adj_list2[temp_list[k]].append(temp_list[l])
				if temp_list[k] not in adj_list2[temp_list[l]]:
					adj_list2[temp_list[l]].append(temp_list[k])
	return adj_list,adj_list2



# print(domain)
					





