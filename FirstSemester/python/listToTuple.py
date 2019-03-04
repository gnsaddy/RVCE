n = int(input("Enter the elements"))
a = []
b = []
for i in range(0, n):
	a.append(int(input("Enter the integer elements: ")))
print(a)


for i in range(0, n):
	b.append(input("Enter the string elements: "))
print(a)

#convert to tuple

a = tuple(a)
b = tuple(b)
print(a)
print(b)
