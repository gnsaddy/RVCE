d = {}
class Employee:
    def getter(self):
        self.name=input("Enter name ")
        self.address=input("Enter address ")
        self.panno=input("Enter pan number")
        self.basic=int(input("Enter basic "))
        self.hra = 1.157*self.basic
        self.da = 0.25*self.basic
        self.cca = 300
        self.pf = 1800
        self.pt = 200
        self.tds=int(input("Enter TDS "))
        self.deduct=int(input("Enter deduct "))
        self.netsal = self.basic+self.da+self.hra +self.cca-(self.pf+self.pt+self.tds+self.deduct)
       
    def Display(self):#Display can be made innovative, here is a sample
        print("name=",self.name)
        print("address=",self.address)
        print("panno=",self.panno)
        print("basic=",self.basic)
        print("hra=",self.hra)
        print("da=",self.da)
        print("cca=",self.cca)
        print("pf=",self.pf)
        print("pt=",self.pt)
        print("tds=",self.tds)
        print("deduct=",self.deduct)
        print("netsal=",self.netsal)

e = Employee()

while True:
    print ("*"*20,"Pay Band Scale","*"*20)
    print ("1--> Enter Employee Details ")
    print ("2--> Display The Employee Details")
    print ("3--> To update to dictionary ")
    print ("4--> To Search Employee in Dictionary ")
    print ("5--> Exit ")
    ch = int(input("Enter the Choice "))
    if ch == 1:
        print("Entered Employee details")
        e.getter()
    elif ch == 2:
        print ("-"*60)
        print ("Display the Employee Details ")
        e.Display()
        print ("-"*60)
    elif ch == 3:
        print ("-"*60)
        print("Updating to Dictionary ")
        d = e.__dict__
        print(d)
        print ("-"*60)
    elif ch == 4:
        print ("-"*60)
        print ("Searching the Name in the Dictionary ")
        print(d.keys())
        k=input("Enter key name to find ")
        print(d[k])
        print ("-"*60)
    elif ch>4:
        break
   
