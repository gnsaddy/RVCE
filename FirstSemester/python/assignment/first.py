def normalDiv():
    f1 = int(input("Enter first number : "))
    f2 = int(input("Enter second number : "))
    if f2 == 0:
        print("Divide by zero exception ")
        return 0
    else:
        print("----------Simple Division operation---------")
        print("Returns the Quotient part with decimal part ")
        result = f1/f2
    print("Division of f1 and f2 is : ", result)
    return result

def modDiv():
    f1 = int(input("Enter first number : "))
    f2 = int(input("Enter second number : "))
    if f2 == 0 :
        print("Divide by zero exception ")
        return 0
    else:
        print("----------Modulo Division operation---------")
        print("Returns the Remainder part  ")
        result = f1%f2
    print("Division of f1 and f2 is : ", result)
    return result

def floorDiv():
    f1 = int(input("Enter first number : "))
    f2 = int(input("Enter second number : "))
    if f2 == 0:
        print("Divide by zero exception ")
        return 0
    else:
        print("----------Floor Division operation---------")
        print("Only returns the exact Quotient value ")
        result = f1//f2
    print("Floor Division of f1 and f2 is : ", result)
    return result

normalDiv()
print("-"*40)
modDiv()
print("-"*40)
floorDiv()

