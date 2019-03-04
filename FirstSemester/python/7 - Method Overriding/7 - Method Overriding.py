# 7. Method Overriding in Python example

class Employee:
    raise_amt = 1.04 #class variable
    def __init__(self,first,last,empid,pay):
        self.first = first
        self.last = last
        self.empid = empid
        self.pay = pay
        
    def apply_raise(self):
        self.pay =  int(self.pay * self.raise_amt)
        return self.pay

    def display(self):
        print ("First Name ==>",self.first)
        print ("Last Name ==>",self.last)
        print ("Employee ID ==>",self.empid)
        print ("Employee Pay ==>",self.pay)
        

class Developer(Employee):
    raise_amt = 1.05 #derived class variable

    def apply_raise(self):
        self.pay =  int(self.pay * self.raise_amt)
        return self.pay
     

class Manager(Employee):
    raise_amt = 1.06

    def apply_raise(self):
        self.pay =  int(self.pay * self.raise_amt)
        return self.pay



emp1 = Manager("Ravi", "Shankar", 1001, 10000)
emp2 = Developer("Shashi", "Kumar", 1002, 12000)


print(emp1.pay) # return the initial pay
print(emp2.pay) # return the initial pay


emp1.apply_raise() # raise for manager
emp2.apply_raise() # raise for developer

#functio call
print(emp1.display())
print(emp2.display())

