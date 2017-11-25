import csv,copy
import sys
def main():
	f=open("aug.txt","r+")
	temp=f.read()
	temp=temp.split('\n')
	rules=[]
	for i in range(1,len(temp)-1):

		temp2=temp[i].split('\t')
		# print(temp2)
		# print(temp2[2])
		if ' and ' in temp2[1]:
			res=[temp2[0][9:]]
			temp2[1]=temp2[1].split(' and ')
			if temp2[1][0][0]!='S':
				temp2[1][0],temp2[1][1]=temp2[1][1],temp2[1][0]
			res+=[temp2[1][0][-1],[temp2[1][1][6:]]]
			
			if res not in rules:
				rules.append(res)
	f.close()
	f=open("sep.txt","r+")
	temp=f.read()
	temp=temp.split('\n')
	for i in range(1,len(temp)-1):
		temp2=temp[i].split('\t')
		if ' and ' in temp2[1]:
			res=[temp2[0][9:]]
			temp2[1]=temp2[1].split(' and ')
			if temp2[1][0][0]!='S':
				temp2[1][0],temp2[1][1]=temp2[1][1],temp2[1][0]
			res+=[temp2[1][0][-1],[temp2[1][1][6:]]]
			if res not in rules:
				rules.append(res)
	f.close()
	f=open("oct.txt","r+")
	temp=f.read()
	temp=temp.split('\n')
	for i in range(1,len(temp)-1):
		temp2=temp[i].split('\t')
		if ' and ' in temp2[1]:
			res=[temp2[0][9:]]
			temp2[1]=temp2[1].split(' and ')
			# print(temp2)
			if temp2[1][0][0]!='S':
				temp2[1][0],temp2[1][1]=temp2[1][1],temp2[1][0]
			res+=[temp2[1][0][-1],[temp2[1][1][6:]]]
			if res not in rules:
				rules.append(res)
	f.close()
	f=open("nov.txt","r+")
	temp=f.read()
	temp=temp.split('\n')
	for i in range(1,len(temp)-1):
		temp2=temp[i].split('\t')
		if ' and ' in temp2[1]:
			res=[temp2[0][9:]]
			temp2[1]=temp2[1].split(' and ')
			if temp2[1][0][0]!='S':
				temp2[1][0],temp2[1][1]=temp2[1][1],temp2[1][0]
			res+=[temp2[1][0][-1],[temp2[1][1][6:]]]
			if res not in rules:
				rules.append(res)
	f.close()
	# print(rules)
	# print (len(rules))
	allrules=copy.deepcopy(rules)
	temp=[]
	for i in range(len(allrules)):
		for j in range(i+1,len(allrules)):
			if allrules[j][2][0] not in allrules[i][2]:
				if allrules[i][0]==allrules[j][0] and allrules[i][1]==allrules[j][1]:
					allrules[i][2]+=allrules[j][2]
					temp.append(j)
	count=0
	for i in list(set(temp)):
		allrules.pop(i-count)
		count+=1
	# print(allrules)
	# for i in rules:
	# 	# print(i)
	# 	if 'TANDOORI FULL' == i[0]:
	# 		print("yes")
	temp=[]
	prices={}
	id_list={}
	item_map=[]
	with open('monthwisePriceList.csv',newline='') as csvfile:
		spamreader=csv.reader(csvfile,quotechar='|')
		for row in spamreader:
			temp.append(row)
	for i in range(1,len(temp)-1):
		item_map.append(int(temp[i][0]))
		if temp[i][1] not in id_list:
			id_list[temp[i][1]]=int(temp[i][0])
		if temp[i][0] not in prices:
			prices[int(temp[i][0])]=int(temp[i][-1])
	# print(prices)
	
	f=open("decdata.txt",'r+')
	temp=f.read()
	temp=temp.split('\n')
	dic={}
	data=[]
	for i in range(1,len(temp)-1):
		temp[i]=temp[i].split(',')
		dic[(int(temp[i][0]),temp[i][2][1:-1],temp[i][3][1:-1])]=int(temp[i][1])
	penalty_hours={1:1,2:4,3:9,4:16,5:25,6:36,7:50,8:50,9:50,10:50,11:50}
	penalty_seg={'1':12,'2':32,'3':30,'4':20,'5':3,'6':2,'7':2,'8':1}
	revenue_change=[]
	penalty=[]
	for i in allrules:
		s=0
		for j in i[2]:
			if (id_list[i[0]],i[1],j) in dic:
				s+=dic[(id_list[i[0]],i[1],j)]
		if 'TANDOORI FULL' == i[0]:
			revenue_change.append(s*10)
			penalty.append(10*penalty_hours[len(i[2])]*penalty_seg[i[1]])
		else:
			revenue_change.append(s*prices[id_list[i[0]]]*0.1)
			penalty.append(0.1*prices[id_list[i[0]]]*penalty_hours[len(i[2])]*penalty_seg[i[1]])
	print("Total change in revenue ",sum(revenue_change))
	print("Total penalty = ",sum(penalty))
	print("Total number of rules = ",len(allrules))
	with open('newPrices.csv','w',newline='') as csvfile:
		spamwriter = csv.writer(csvfile,delimiter=",")
		outputrow=["ItemID","SellingPriceDec","times","new F1","new F2","new F3","new F4","new F5","new H1","new H2","new others"]
		spamwriter.writerow(outputrow)
		for i in range(1,len(id_list)+1):
			for j in range(11):
				temp=[]
				ans=[]
				for k in allrules:
					if id_list[k[0]]==item_map[i-1] and str(j+16) in k[2]:
						temp+=[int(k[1])]
				for k in range(8):
					if k+1 in temp:
						if item_map[i-1] ==180:
							ans.append(180)
						else:
							ans.append(1.1*prices[item_map[i-1]])
					else:
						ans.append(prices[item_map[i-1]])
				# print(i,ans)
				outputrow=[item_map[i-1],prices[item_map[i-1]],j+16]+ans
				spamwriter.writerow(outputrow)

main()