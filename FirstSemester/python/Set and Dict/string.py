while True:
    print("1.contact")
    print("2.reverse")
    print("3.upper")
    print("3.lower")
    print("4.reverse")
    print("5.substring")
    print("6.remove white space")
    print("7.is digit")
    print("8.is aplaha")
    print("9.len")
    print("10.print")

    n=input("Enter a string");
    n1=input("Enter the new string")
    ch=int(input("Enter the choice"))

    if ch==1:
        print(n+n1)
    elif ch==2:
        print(n1[::-1])
    elif ch==3:
        print(n1.upper())
    elif ch==4:
        print(n1.lower())
    