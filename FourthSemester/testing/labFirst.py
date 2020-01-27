def triangle():
    a = int(input("Enter length of first side : "))
    b = int(input("Enter length of second side : "))
    c = int(input("Enter length of third side : "))

    if a > 0 and b > 0 and c > 0:
        if a > b + c and b > a + c and c > b + c:
            