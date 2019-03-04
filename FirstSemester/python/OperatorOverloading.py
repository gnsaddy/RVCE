class opeover:
    def __init__(self):
        self.alist=[]

    def get_element(self):
        n=int(input("\nEnter list size\n"))
        for i in range(0,n):
            item=int(input("Enter list element "))
            self.alist.append(item)
        return self.alist

    def __add__(self,other):
        new_list = []
        for i in range(0,len(self.alist)):
            new_list.append(self.alist[i]+other.alist[i])
        return new_list
         
    def __sub__(self,other):
        new_list = []
        for i in range(0,len(self.alist)):
            new_list.append(self.alist[i]-other.alist[i])
        return new_list 

    def __mul__(self,other):
        new_list = []
        for i in range(0,len(self.alist)):
            new_list.append(self.alist[i]*other.alist[i])
        return new_list
    
    def __floordiv__(self,other):
        new_list = []
        for i in range(0,len(self.alist)):
            new_list.append(self.alist[i]//other.alist[i])
        return new_list


ov1 = opeover()
ov2 = opeover()

ov1.get_element()
print(ov1.alist)
ov2.get_element()
print(ov2.alist)

while True:
    print("-" * 60)
    print("           MENU            ")
    print("-" * 60)
    print(" 1. Oveload + operator\n 2. Overload - Operator\n 3. Over load * \n 4.Overload // \n 5. Quit")
    ch = int(input("Enter Your Choice : "))

    if ch == 1:
        print(ov1+ov2)  # + is over loaded

    elif ch == 2:
        print(ov1-ov2)  # - is over loaded

    elif ch == 3:
        print(ov1*ov2)  # * is over loaded

    elif ch == 4:
        print(ov1//ov2)  # // is over loaded

    elif ch == 5:
        break

    else:
        print("Invalid choice")
