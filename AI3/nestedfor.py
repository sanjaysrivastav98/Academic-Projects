# 2015A7PS0102P K S Sanjay Srivastav
from preprocessing import ltp,domain
def func(count,course):
	temp=[]
	if count==0:
		return [[]]
	elif count==1:
		for i0 in range(len(domain[course])):
			temp.append([domain[course][i0]])
	elif count==2:
		for i0 in range(len(domain[course])):
			for i1 in range(i0+1,len(domain[course])):
				temp.append([domain[course][i0],domain[course][i1]])
	elif count==3:
		for i0 in range(len(domain[course])):
			for i1 in range(i0+1,len(domain[course])):
				for i2 in range(i1+1,len(domain[course])):
					temp.append([domain[course][i0],domain[course][i1],domain[course][i2]])
	elif count==4:
		for i0 in range(len(domain[course])):
			for i1 in range(i0+1,len(domain[course])):
				for i2 in range(i1+1,len(domain[course])):
					for i3 in range(i2+1,len(domain[course])):
						temp.append([domain[course][i0],domain[course][i1],domain[course][i2],domain[course][i3]])
	elif count==5:
		for i0 in range(len(domain[course])):
			for i1 in range(i0+1,len(domain[course])):
				for i2 in range(i1+1,len(domain[course])):
					for i3 in range(i2+1,len(domain[course])):
						for i4 in range(i3+1,len(domain[course])):
							temp.append([domain[course][i0],domain[course][i1],domain[course][i2],domain[course][i3],domain[course][i4]])
	elif count==6:
		for i0 in range(len(domain[course])):
			for i1 in range(i0+1,len(domain[course])):
				for i2 in range(i1+1,len(domain[course])):
					for i3 in range(i2+1,len(domain[course])):
						for i4 in range(i3+1,len(domain[course])):
							for i5 in range(i4+1,len(domain[course])):
								temp.append([domain[course][i0],domain[course][i1],domain[course][i2],domain[course][i3],domain[course][i4],domain[course][i5]])
	return temp
    
   	
    