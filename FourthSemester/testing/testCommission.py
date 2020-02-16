def testCom():
    global locks, stocks, barrels, totalSales, commission
    global lsales, ssales, bsales
    lockPrice = 45
    stockPrice = 30
    barrelPrice = 25
    count = 0
    totalLock = 0
    totalStocks = 0
    totalBarells = 0
    locks = int(input("Enter the total number of locks : "))
    while locks != -1:
        stocks = int(input("Enter the total number of stocks : "))
        barrels = int(input("Enter the total number of barrels : "))
        if locks < 1 or locks > 70 and stocks < 1 or stocks > 80 and barrels < 1 or barrels > 90:
            count = 1
            print("Invalid Input")
            exit()
        else:
            totalLock += locks
            totalStocks += stocks
            totalBarells += barrels
            locks = int(
                input("Enter the number of locks and to exit the loop enter -1 for locks :- "))

    print("total locks :- ", totalLock)
    print("total stocks :- ", totalStocks)
    print("total barrel :- ", totalBarells)
    lsales = (totalLock * lockPrice)
    ssales = (totalStocks * stockPrice)
    bsales = (totalBarells * barrelPrice)
    totalSales = lsales + ssales + bsales
    print("Total sales is : ", totalSales)
    if totalSales in range(1001, 1801):
        commission = 0.10 * 1000
        commission = commission + (0.15 * (totalSales - 1000))
    elif totalSales > 1800:
        commission = 0.10 * 1000  # for less than 1000
        commission = commission + (0.15 * 800)  # for range in 1000,1800
        commission = commission + (0.20 * (totalSales - 1800))  # above 1800
    else:
        commission = 0.10 * totalSales
    print("Commission is : ", commission)


testCom()
while True:
    print("Want to retest yes(1) or no(0)")
    ch = int(input("Enter 1 or 0 : "))
    if ch == 1:
        testCom()
    if ch == 0:
        print("Testing done!!Leaving")
        exit()
