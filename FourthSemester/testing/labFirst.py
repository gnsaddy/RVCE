def triangle():
    a = int(input("Enter length of first side : "))
    b = int(input("Enter length of second side : "))
    c = int(input("Enter length of third side : "))

    if a > 0 and b > 0 and c > 0:
        if a < b + c and b < a + c and c < a + b:
            if a == b and b == c and c == a:
                print("Equilateral triangle")
            elif a != b and b != c and a != c:
                print("Scalene triangle")
            elif a == b or b == c or a == c:
                print("Isosceles triangle")

        else:
            print("Triangle can not be formed")
    else:
        print("Invalid dimension")


triangle()
while True:
    print("Want to retest yes(y) or no(n)")
    ch = input("Enter y or n : ")
    if ch == 'y':
        triangle()
    if ch == 'n':
        print("Testing done!!Leaving")
        exit()
