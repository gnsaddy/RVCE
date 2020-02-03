

def test():
    day = int(input("Input a day [1-31]: "))
    month = int(input("Input a month [1-12]: "))
    year = int(input("Input a year: "))

    if (year % 4 == 0):
        if (year % 100 == 0):
            if (year % 400 == 0):
                leap_year = True
            else:
                leap_year = False
        else:
            leap_year = True
    else:
        leap_year = False

    if month in (1, 3, 5, 7, 8, 10, 12):
        month_length = 31
    elif month == 2:
        if leap_year:
            month_length = 29
        else:
            month_length = 28
    else:
        month_length = 30

    if (year in range(1981, 2021)):
        if (month_length in range(1, 32)):
            if (month in range(1, 13)):

                if day < month_length:
                    day += 1
                else:
                    day = 1
                    if month == 12:
                        month = 1
                        year += 1
                    else:
                        month += 1
                if year > 2020:
                    print("Invalid year")
                else:
                    print("The next date is [yyyy-mm-dd] %d-%d-%d." %
                          (day, month, year))

            else:
                print("Invalid Input month")
        else:
            print("Invalid Input Date")
    else:
        print("Invalid Input Year")


test()
while True:
    print("Want to retest yes(y) or no(n)")
    ch = input("Enter y or n : ")
    if ch == 'y':
        test()
    if ch == 'n':
        print("Testing done!!Leaving")
        exit()
