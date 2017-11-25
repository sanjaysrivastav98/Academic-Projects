#2015A7PS0102P K S Sanjay Srivastav

from __future__ import print_function
from preprocessing import ltp,domain,CSP,generate_package,printf,Constraint_Graph,ltp_generator
from techniques import DFS_BT,DFS_BT_CP
import csv

def main():
	N=int(raw_input("Enter an option: "))
	testcasefile=open("testcasefile.csv","rb")
	if N==1:
		program_Dictionary,prof_Dictionary=generate_package(testcasefile)
		package=program_Dictionary,prof_Dictionary
		printf(package[0])
		for i in package[1]:
			print(i," : ",package[1][i])
		# print(package[1])
	# printf(program_Dictionary)
	# print(prof_Dictionary)
	elif N==2:
		program_Dictionary,prof_Dictionary=generate_package(testcasefile)
		package=program_Dictionary,prof_Dictionary
		CG=Constraint_Graph(package)
		ltp_generator(CSP)
		for i in range(len(ltp)):
			course="C_"
			if i<9:
				course+="0"+str(i+1)
			else:
				course+=str(i+1)
			temp=[]
			if course in CG[0]:
				temp+=CG[0][course]
			if course in CG[1]:
				temp+=CG[1][course]
			temp=list(set(temp))
			print(course+" : ",temp)

	elif N==3:
		program_Dictionary,prof_Dictionary=generate_package(testcasefile)
		package=program_Dictionary,prof_Dictionary
		CG=Constraint_Graph(package)
		ltp_generator(CSP)
		result=DFS_BT(CSP,[],CG)
		print(result[1])
	elif N==4:
		program_Dictionary,prof_Dictionary=generate_package(testcasefile)
		package=program_Dictionary,prof_Dictionary
		CG=Constraint_Graph(package)
		ltp_generator(CSP)
		result=DFS_BT_CP(CSP,[],CG)
		print(result[1])

main()
