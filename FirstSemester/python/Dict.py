import random
a = {}
n = int(input("Enter the List of Element and key to be added \n"))
for i in range(0,n):
    b = input("Enter the Key Value ")
    m = int(input("Enter the List of Element and key to be added \n"))
    c = []
    for i in range (0,m):
        c.append(input("Enter the Value of key"))
    a[b] = c
print(a)
while True:
    print ("1---------> Updating Dict ")
    print ("2---------> Length of Dict ")
    print ("3---------> List of Items ")
    print ("4---------> Clear the contents")

    print ("11---------> Exit")
    ch=int(input("Enter your choice\n"))
    if ch==1:
        n = int(input("Enter the List of Element and key to be added \n"))
        for i in range(0,n):
            b = input("Enter the Key Value ")
            c = input("Enter the Value of key %s "%b)
            a[b] = c
        print ("-"*60)
        print (a)
        print ("-"*60)
    if ch==2:
        print ("-"*60)
        print ("Length of Dict", a, "=== > ",len(a))
        print ("-"*60)
    if ch==3:
        print ("-"*60)
        print ("Displaying the Items of Dict",a," === > ",a.keys())
        print ("-"*60)
                               
