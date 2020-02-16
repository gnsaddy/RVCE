def testCom():
    global locks, stocks, barrels, totalSales, commission
    lockPrice, stockPrice, barrelPrice = 45, 30, 25
    count = 0
    locks = int(input("Enter the total number of locks : "))
    if locks < 1 or locks > 70:
        count = 1
    stocks = int(input("Enter the total number of stocks :"))
    if stocks < 1 or stocks > 80:
        count = 1
    barrels = int(input("Enter the total number of barrels :"))
    if barrels < 1 or barrels > 90:
        count = 1
    if count == 1:
        print("Invalid Input")
        exit()
    totalSales = (locks * lockPrice) + (stocks * stockPrice) + \
        (barrels * barrelPrice)
    if totalSales <= 1000:
        commission = 0.10 * totalSales
    elif totalSales in range(1001, 1801):
        commission = 0.10 * 1000
        commission = commission + (0.15 * (totalSales - 1000))
    elif totalSales > 1800:
        commission = 0.10 * 1000  # for less than 1000
        commission = commission + (0.15 * 800)  # for range in 1000,1800
        commission = commission + (0.20 * (totalSales - 1800))  # above 1800
    print("Total sales is : ", totalSales)
    print("Commission is : ", commission)


testCom()
while True:
    print("Want to retest yes(y) or no(n)")
    ch = input("Enter y or n : ")
    if ch == 'y':
        testCom()
    if ch == 'n':
        print("Testing done!!Leaving")
        exit()
