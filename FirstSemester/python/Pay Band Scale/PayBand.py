d = {}
class Employee:
    def Salary_slip(self, name, address,panno,basic,TDS=0,Deduct=0):
        self.name=name
        self.address=address
        self.panno=panno
        self.basic = basic
        self.hra = 1.157*basic
        self.da=0.25*basic
        self.cca=300
        self.pf=1800
        self.pt=200
        self.tds=TDS
        self.deduct=Deduct
        netsal = self.basic+self.da+self.hra+self.cca-(self.pf+self.pt+self.tds+self.deduct)
        return netsal

    def accept(self):
        name=input("enter the Employee name: ")
        address=input("enter the "+name+" address: ")
        panno=input("enter the "+name+" panno: ")
        basic =int(input("enter the "+name+" Basic: "))
        tds =int(input("enter the "+name+" tds: "))
        deduct =int(input("enter the "+name+" Deduct: "))
        self.netsal = self.Salary_slip(name,address,panno,basic,tds,deduct)
       
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
   
    def search(self,name):
        for k,v in d.items():
            if k==name:
                print("name : {0}, address : {1},panno : {2}".format(v.name, v.address,v.panno,))
                print("basic : {0},hra : {1},da:{2},cca:{3},pf:{4},pt:{5}".format(v.basic,v.hra,v.da,v.cca,v.pf,v.pt))
                print("tds : {0},deduct : {1}".format(v.basic,v.hra))
                print("netsal=",v.netsal)

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
        e=Employee()
        print(id(e))
        e.accept()
    elif ch == 2:
        print ("-"*60)
        print ("Display the Employee Details ")
        e.Display()
        print ("-"*60)
    elif ch == 3:
        print ("-"*60)
        print("Updating to Dictionary ")
        d.update({e.name:e}) # inbuilt
        print(d)
        print ("-"*60)
    elif ch == 4:
        print ("-"*60)
        print ("Searching the Name in the Dictionary ")
        e.search(input("Enter the Name" ))
        #search module can be added as a extra feature
        print ("-"*60)
    elif ch == 5:
        break
    else:
        print ("-"*60)
        print ("Plz Enter Valid Choice ")
        print ("-"*60)
        

