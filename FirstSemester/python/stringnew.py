n1=input("Enter the string");
n2=input("ENter the string")
while True:
    print ("1 -- > join ")
    print ("2 -- > to upper ")
    print ("3 -- > lower ")
    print ("4 -- > len ")
    print ("5 -- > rev ")
    print ("6 -- > without white space ")
    print ("7 -- > sort ")
    print ("8 -- > check is digit or not ")
    print ("9 -- > substr ")
    print ("10 -- > find ")
    print ("11 -- > ispace ")
    choice = int(input("Enter your Choice "))
    if choice == 1:
        print (n1+n2)
        
    elif choice == 2:
       
        print (n1.upper())
    elif choice == 4:
       
        print (len(n1))
    elif choice == 5:
           
        print (n1[::-1])
    elif choice == 6:
           
        print (n2.strip())
    elif choice == 7:
           
        print (n1.sort())
    elif choice == 8:
           
        print (n1.isdigit())
    elif choice == 9:
           
        print (n1[2:5])

    elif choice == 10:
           
        print (n1.find("hello"))
    elif choice == 11:
           
        print(n1.isspace())
        