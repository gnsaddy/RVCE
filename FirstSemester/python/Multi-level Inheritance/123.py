class student:
    def __init__(self,usn=0,name=0,age=0):
        self.usn=usn
        self.name=name
        self.age=age
    def input(self):
        self.usn=input("Enter  usn")
        self.name=input("Enter the usn")
        self.age=input("Ente the age")
    def dis(self):
        print("usn==",self.usn)
        print("name=",self.name)
        print("age=",self.age)
class newstudent(student):
    def __init__(self,m1=0,m2=0,m3=0):
        self.m1=m1
        self.m2=m2
        self.m3=m3
    def sinput(self):
        self.m1=int(input("Enter the m1"))
        self.m2=int(input("Enter the m2"))
        self.m3=int(input("Enter the m3"))
    def sdis(self):
        print("m1",self.m1)
        print("m2",self.m2)
        print("m3",self.m3)
        self.ttl=self.m1+self.m2+self.m3
        print(self.ttl)
        self.per=self.ttl/3
        print(self.per)
class Results(newstudent):
    # Method
    def dResults(self):
        print("\n\nName: ",self.name)
        print("\n\nName: ",self.usn)
        print("Age: ",self.age)
        
        
        
        print("Total Marks: ",self.ttl)
       
        print("Percentage of",self.per)
res=Results()
res.input()
res.sinput()
res.sdis()
res.dResults()


