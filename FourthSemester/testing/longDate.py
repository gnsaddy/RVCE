def retest():
    print("Re-enter : ")
    testDate()


def testDate():
    global nd, nm, ny
    d = int(input("Enter date : "))
    m = int(input("Enter month : "))
    y = int(input("Enter year : "))
    flag = True
    print("Given date is : ", d, "-", m, "-", y)
    if (y % 4) == 0:
        if (y % 100) == 0:
            if (y % 400) == 0:
                lpy = True
                print("{0} is a leap year".format(y))
            else:
                lpy = False
                print("{0} is not a leap year".format(y))
        else:
            lpy = True
            print("{0} is a leap year".format(y))
    else:
        lpy = False
        print("{0} is not a leap year".format(y))

    if m in (1, 3, 5, 7, 8, 10, 12):
        flag = True
        print("31 days - month", m)
        count = 31

        print("day count : ", count)
    elif m in (4, 6, 9, 11):
        flag = False
        print("30 days - month", m)
        count = 30

        print("day count : ", count)
    elif m == 2:
        if lpy:
            print("29 days - month", m)
            count = 29
            print("day count : ", count)
        else:
            print("28 days - month", m)
            count = 28
            print("day count : ", count)

    if d not in range(1, 32):
        retest()
    elif (flag is True and d not in range(1, 32)):
        print("------------Invalid Input Date(1-31)-----------")
        retest()
    elif (flag is False and d not in range(1, 31)):
        print("------------Invalid Input Date(1-30)-----------")
        retest()
    if m == 2:
        if (lpy is True and d not in range(1, 30)):
            print("------------Invalid Input Date(1-29)-----------")
            retest()
        elif lpy is False and d not in range(1, 29):
            print("------------Invalid Input Date(1-28)-----------")
            retest()
    if y not in range(1986, 2021):
        print("------------Invalid Input Year-----------")
        retest()
    elif m not in range(1, 13):
        print("------------Invalid Input Month-----------")
        retest()

    nd = d+1
    nm = m
    ny = y

    if nd > count:
        nd = 1
        nm = nm + 1
    if (nm > 12):
        nm = 1
        ny = ny+1

    print("The next date is : ", nd, "-", nm, "-", ny)


testDate()
while True:
    print("Want to retest yes(y) or no(n)")
    ch = input("Enter y or n : ")
    if ch == 'y':
        testDate()
    if ch == 'n':
        print("Testing done!!Leaving")
        exit()
