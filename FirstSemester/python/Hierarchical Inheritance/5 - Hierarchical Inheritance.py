#Inheritance program
class student: #base class
    def __init__(self, USN=' ', name=' ', age=0):
        self.USN=USN
        self.name=name
        self.age=age
    def get_data(self):
        self.USN=input("Enter USN")
        self.name=input("Enter Student name")
        self.age=int(input("Enter age"))
    def display(self):
         print("USN:",self.USN)
         print("STUDENT NAME",self.name)
         print("STUDENT AGE",self.age)             
                     
class PGstudent(student): #Derived class
    def __init__(self, sem=0, fee=0, staipend=0):
            self.sem=sem
            self.fee=fee
            self.staipend=staipend
    def get_PGinfo(self):
            self.sem=int(input("Enter Semester "))
            self.fee=input("Enter Student fee ")
            self.staipend=input("Enter staipend ")
    def PGdisplay(self):
        print("SEMESTER:",self.sem)
        print("FEE PAID:", self.fee)
        print("STAIPEND GETTING:",self.staipend)

class UGstudent(student): #Derived class
    def __init__(self, sem=0, fee=0, staipend=0):
            self.sem=sem
            self.fee=fee
            self.staipend=staipend
    def get_UGinfo(self):
            self.sem=int(input("Enter Semester "))
            self.fee=input("Enter Student fee ")
            self.staipend=input("Enter staipend ")
    def UGdisplay(self):
        print("SEMESTER: ",self.sem)
        print("FEE PAID: ", self.fee)
        print("STAIPEND GETTING: ",self.staipend)


pgs=PGstudent()
ugs=UGstudent()
while True:
    print("-" *60)
    print("MENU")
    print("-" *60)
    print(" 1. PG Details ")
    print(" 2. UG Details ")
    ch = int(input("Enter Your Choice\n"))
    if ch == 1:
        pgs.get_data()
        pgs.get_PGinfo()
        print("PG Details ")
        pgs.display()
        pgs.PGdisplay()
        print("-" *60)
    elif ch == 2:
        ugs.get_data()
        ugs.get_UGinfo()
        print("UG Details ")
        ugs.display()
        ugs.UGdisplay()
        print("-" *60)
    else:
        print("Invalid Choice\n")
        break;
                    
          
    
