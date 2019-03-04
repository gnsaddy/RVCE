import random
lst1 = [[],[],[]]
lst2 = [[],[],[]]
print("Empty list ",lst1,"\n",lst2)
result = [[0, 0, 0],
          [0, 0, 0],
          [0, 0, 0]]
          
for i in range(0,3):
    lst1[0].append(random.randint(1, 9))
    lst1[1].append(random.randint(1, 9))
    lst1[2].append(random.randint(1, 9))
print("-"*60)
for i in range(0, 3):
    lst2[0].append(random.randint(1, 9))
    lst2[1].append(random.randint(1, 9))
    lst2[2].append(random.randint(1, 9))

print("List with values ")
for i in lst1:
    print(i)
print("-"*60)
for i in lst2:
    print(i)

print("-"*60)
print("Matrix multiplication of 3*3 matrix : ")

for i in range(len(lst1)):
    # iterating by coloum of list 2
    for j in range(len(lst2[0])):
        # iterating by rows of list 2
        for k in range(len(lst2)):
            result[i][j] = result[i][j] + lst1[i][k] * lst2[k][j]
for r in result:
    print(r)

