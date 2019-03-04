import os
from OperatorOverloading import *

os.system('clear')        
ov1=opeover()
ov2=opeover()

ov1.get_element()
print(ov1.alist)
ov2.get_element()
print(ov2.alist)



while True:
    print("-" *60)
    print("           MENU            ")
    print("-" *60)
    print(" 1. Oveload + operator\n 2. Overload - Operator\n 3. Over load * \n 4.Overload // \n 5. Quit")
    ch = int(input("Enter Your Choice"))

    if ch == 1:
        print(ov1+ov2) #         + is over loaded
        
    elif ch == 2:
        print(ov1-ov2) #         - is over loaded
        
    elif ch == 3:
        print(ov1*ov2) #          * is over loaded
        
    elif ch == 4:
        print(ov1//ov2) #         // is over loaded

    elif ch == 5:
        break

    else:
        print("Invalid choice")
