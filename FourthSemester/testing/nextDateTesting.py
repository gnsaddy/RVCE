def DateTest():

    d = int(input("Enter date : "))
    m = int(input("Enter month : "))
    y = int(input("Enter year : "))
    month31 = 31
    month30 = 30

    if m in (1, 3, 5, 7, 8, 10, 12):
        ndays = month31
    elif m in (4, 6, 9, 11):
        ndays = month30

    if(m == 2):
        if(y % 4 == 0):
            if(y % 100 == 0):
                if (y % 400 == 0):
                    ndays = 29
                    print("leap year")
                else:
                    ndays = 28
                    print("not leap year")
            else:
                ndays = 29
                print("leap year")
        else:
            ndays = 28
            print("not leap year")

    if (y in range(1985, 2021)):
        if (d in range(1, ndays+1)):
            if (m in range(1, 13)):

                nextdate = d+1
                nextmonth = m
                nextyear = y

                if(nextdate > ndays):
                    nextdate = 1
                    nextmonth = nextmonth+1

                if(nextmonth > 12):
                    nextmonth = 1
                    nextyear = nextyear+1

                print("Given date is : ", d, "-", m, "-", y)

                if (nextyear < 2021):
                    print("Next day's date is : ", nextdate,
                          "-", nextmonth, "-", nextyear)
                else:
                    print("Invalid next year")

            else:
                print("Invalid Input month")
        else:
            print("Invalid Input Date")
    else:
        print("Invalid Input Year")


DateTest()
while True:
    print("Want to retest yes(y) or no(n)")
    ch = input("Enter y or n : ")
    if ch == 'y':
        DateTest()
    if ch == 'n':
        print("Testing done!!Leaving")
        exit()
