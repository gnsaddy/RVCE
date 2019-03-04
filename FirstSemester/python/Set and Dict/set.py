set1={1,2,3,4,5,6,7,8}
set2={3,4,5,6,7,8}
while 1:
	print("1.Size of the set")
	print("2.Length of the set")
	print("3.Add new value")
	print("4.Pop")
	print("5.Union")
	print("6.Intersection")
	print("7.Set Difference")
	print("8.Symmetric difference")
	print("9.Check for a element in a set")
	print("10.Clear a Set")
	ch=int(input("Enter the choice"))
	if ch==1:
		print(set1)
		print("size:",set1.__sizeof__())
		print(set2)
		print("size:",set2.__sizeof__())
	elif ch==2:
		print(set1," length:",len(set1))
		print(set2," length:",len(set2))
	elif ch==3:
		new=int(input("Enter the new Element to be added"))
		set1.add(new)
		print (set1)
	elif ch==4:
		set1.pop()
		print(set1)
	elif ch==5:
		print("Union of Set1 and Set2:")
		print(set1.union(set2))
	elif ch==6:
		print("Intersection of Set1 and Set2:")
		print(set1.intersection(set2))
	elif ch==7:
		print("Set Difference")
		print("set1-set2=",set1-set2)
		print("set2-set1",set2-set1)
	elif ch==8:
		print("Symmetric Difference")
		print(set1^set2)
	elif ch==9:
		value=int(input("Enter the value to be check"))
		print(set1.__contains__(value))
	elif ch==10:
		set1.clear();
		print("Cleared")
	elif ch==11:
		exit();
	else:
		print("Invalid Input")
	
		
		
