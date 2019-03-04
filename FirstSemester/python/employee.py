# 1) WAP for employee with empid,ename,pay,email,dept and
#  initilize the objects with data.Disolay the employee 
#  information and number of employee objects created.

# 2) setattr(obj,name,value)
# getattr(obj,attribute)
# hasattr(obj,attribute)
# delattr(obj,attribute)


class Employee:
    count = 0

    def __init__(self,eid,ename,pay):
        self.eid = eid
        self.ename = ename
        self.pay = pay
        self.email = ename+"@"+"gmail.com"
        Employee.count += 1


    # def getEmp(self):
    #     self.eid = int(input("Enter employee id "))
    #     self.ename = input("Enter employee name ")
    #     self.pay = int(input("Enter employee pay "))
    #     self.email = input("Enter employee email ")

    def display(self):
        print("Employee name : ",self.ename)
        print("Employee id : ",self.eid)
        print("Employee pay : ",self.pay)
        print("Employee email : ", self.email)
        print("Count",Employee.count)


print("Employee first details : ")
emp1 = Employee(12345,"Aditya",4500)
emp1.display()
print("-"*50)
print("Employee second details : ")
emp2 = Employee(4567,"Akash",50000)
emp2.display()
print("-"*50)
# print("Number of employees are : ",Employee.count)

# print("-"*50)
# print(emp1.__dict__)
# print(emp2.__dict__)

# print("-"*50)
# # print(setattr(emp1,"id",5689))
# print(getattr(emp2,"ename"))
# print(hasattr(emp1,"ename"))
# print(delattr(emp2,"ename"))

# print("-"*50)


# emp1.display()
# emp2.display()



