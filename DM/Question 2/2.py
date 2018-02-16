import sys,csv


def main():
	f=open("aug.txt","r+")
	temp=f.read()
	temp=temp.split('\n')
	combo=[]
	for i in range(1,len(temp)-1):
		temp2=temp[i].split('\t')
		temp2[1]=temp2[1].split(' and ')
		# print(temp2[1])
		res=[temp2[0]]
		for j in temp2[1]:
			res+=[j]
		combo.append(res)
	f.close()
	f = open("sep.txt", "r+")
	temp = f.read()
	temp = temp.split('\n')
	for i in range(1, len(temp) - 1):
		temp2 = temp[i].split('\t')
		temp2[1] = temp2[1].split(' and ')
		# print(temp2[1])
		res = [temp2[0]]
		for j in temp2[1]:
			res += [j]
		if res not in combo:
			combo.append(res)
	f.close()
	f = open("oct.txt", "r+")
	temp = f.read()
	temp = temp.split('\n')
	for i in range(1, len(temp) - 1):
		temp2 = temp[i].split('\t')
		temp2[1] = temp2[1].split(' and ')
		# print(temp2[1])
		res = [temp2[0]]
		for j in temp2[1]:
			res += [j]
		if res not in combo:
			combo.append(res)
	f.close()
	f = open("nov.txt", "r+")
	temp = f.read()
	temp = temp.split('\n')
	for i in range(1, len(temp) - 1):
		temp2 = temp[i].split('\t')
		temp2[1] = temp2[1].split(' and ')
		# print(temp2[1])
		res = [temp2[0]]
		for j in temp2[1]:
			res += [j]
		if res not in combo:
			combo.append(res)
	f.close()
	
	f=open("decdata.txt","r+")
	temp2=f.read().split('\n')
	pricedata=temp2
	dic={}
	dic2={}
	id_list={}
	temp=[]
	for i in range(1,len(temp2)-1):
		temp.append(temp2[i].split(','))
	for i in range(1,len(temp)-1):
		

		if (temp[i][1],temp[i][3][1:-1]) in dic:
			if "ItemName_"+temp[i][4][1:-1] not in dic[(temp[i][1],temp[i][3][1:-1])]:
				dic[(temp[i][1],temp[i][3][1:-1])].append("ItemName_"+temp[i][4][1:-1])
				dic2[(temp[i][1],temp[i][3][1:-1])].append(int(temp[i][2]))
			else:
				for j in range(len(dic[(temp[i][1],temp[i][3][1:-1])])):
					if dic[(temp[i][1],temp[i][3][1:-1])][j] == "ItemName_"+temp[i][4][1:-1]:
						dic2[(temp[i][1],temp[i][3][1:-1])][j]+=int(temp[i][2])
						break

		else:
			dic[(temp[i][1],temp[i][3][1:-1])]=["ItemName_"+temp[i][4][1:-1]]
			dic2[(temp[i][1],temp[i][3][1:-1])]=[int(temp[i][2])]
	# print(id_list)
	f.close()

	itemprice={}
	with open('monthwisePriceList.csv',newline='') as csvfile:
		spamreader=csv.reader(csvfile,quotechar='|')
		temp=[]
		for row in spamreader:
			temp.append(row)
	# print(len(temp)-1)
	for i in range(1,len(temp)):
		# print(temp[i],i)
		if temp[i][1] not in id_list:
			id_list[temp[i][1]]=int(temp[i][0])
		if "ItemName_"+temp[i][1] not in itemprice:
			itemprice["ItemName_"+temp[i][1]]=int(temp[i][-1])
	# print(itemprice)
	f=open("dectest.txt","r+")
	temp=f.read().split('\n')
	# print(dic2)

	headers={}
	temp2=temp[0].split(',')
	for i in range(len(temp2)):
		headers[temp2[i]]=i
	decsales=[]
	for i in range(1,len(temp)-1):
		temp2=temp[i].split(',')
		temp3=[temp2[0]]
		for j in range(1,len(temp2)):
			temp3.append(temp2[j][1:-1])
		decsales.append(temp3)
	# print(decsales[0])
	# for i in decsales:
	# 	print(i)
	# print(decsales)
	final_list=[]
	count=0
	for i in combo:
		flag=0
		count1=0
		count2=0
		count3=0
		if len(i)==2:
			for j in decsales:
				if j[headers[i[0]]]=="T" and j[headers[i[1]]]=="T":
					# print(j[0],j[1])
					count1+=dic2[(j[0],j[1])][dic[(j[0],j[1])].index(i[0])]
					count2+=dic2[(j[0],j[1])][dic[(j[0],j[1])].index(i[1])]
			# print(count2,count1)
			if count1>0 and count2>0:
				final_list.append((count,min(count2,count1)*(itemprice[i[0]]+itemprice[i[1]])*(0.1)))
		else:
			for j in decsales:
				if j[headers[i[0]]]=="T" and j[headers[i[1]]]=="T" and j[headers[i[2]]]=="T":
					count1+=dic2[(j[0],j[1])][dic[(j[0],j[1])].index(i[0])]
					count2+=dic2[(j[0],j[1])][dic[(j[0],j[1])].index(i[1])]
					count3+=dic2[(j[0],j[1])][dic[(j[0],j[1])].index(i[2])]
			if count1 > 0 and count2 > 0 and count3>0:
				final_list.append((count,min(count2,count1,count3)*(itemprice[i[0]]+itemprice[i[1]]+itemprice[i[2]])*(1/15)))
		count+=1

	final_list=sorted(final_list,key=lambda x: x[1],reverse=True)
	# print(final_list)
	s=0
	temp_list=[]
	for i in final_list:
		s+=i[1]
		temp_list+=[i[0]]
		if s>91275.440:
			s-=i[1]
			break
	print("Total loss = ",s)
	print("Total number of combos = ",len(combo))
	
	with open('output2.csv', 'w',newline='') as csvfile:
		spamwriter = csv.writer(csvfile,delimiter=",")
		outputrow=['newItemID','oldPriceSum','newPrice','items']
		spamwriter.writerow(outputrow)
		count=1
		for i in final_list:
			# print(combo[i[0]])
			if len(combo[i[0]])==2:
				var=str(id_list[combo[i[0]][0][9:]])+","+str(id_list[combo[i[0]][1][9:]])
				outputrow=[str(count),str(itemprice[combo[i[0]][0]]+itemprice[combo[i[0]][1]]),str(0.9*(itemprice[combo[i[0]][0]]+itemprice[combo[i[0]][1]])),var]
			else:
				var=str(id_list[combo[i[0]][0][9:]])+","+str(id_list[combo[i[0]][1][9:]])+","+str(id_list[combo[i[0]][2][9:]])
				outputrow=[str(count),str(itemprice[combo[i[0]][0]]+itemprice[combo[i[0]][1]]+itemprice[combo[i[0]][2]]),str((1-1/15)*(itemprice[combo[i[0]][0]]+itemprice[combo[i[0]][1]]+itemprice[combo[i[0]][2]])),var]
			spamwriter.writerow(outputrow)
			
			count+=1
		for i in range(len(combo)):
			if i not in temp_list:
				if len(combo[i]) == 2:
					var = str(id_list[combo[i][0][9:]]) + "," + str(id_list[combo[i][1][9:]])
					outputrow = [str(count), str(itemprice[combo[i][0]] + itemprice[combo[i][1]]),str(0.9 * (itemprice[combo[i][0]] + itemprice[combo[i][1]])), var]
				else:
					var = str(id_list[combo[i][0][9:]]) + "," + str(id_list[combo[i][1][9:]]) + "," + str(id_list[combo[i][2][9:]])
					outputrow = [str(count),str(itemprice[combo[i][0]] + itemprice[combo[i][1]] + itemprice[combo[i][2]]),str((1 - 1 / 15) * (itemprice[combo[i][0]] + itemprice[combo[i][1]] + itemprice[combo[i][2]])),var]
				spamwriter.writerow(outputrow)
				count+=1
 



main()
