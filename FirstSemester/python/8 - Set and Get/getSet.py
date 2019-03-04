class Employee(object):
   
    def __setattr__(self, name, value):
        #print(name)
        if name=="empno" or name=="empname" or name=="designation" or name=="empstatus":
            self.__dict__[name] = value
            print("value set for %s -- %s"%(name,value))
        else:
            print("cannot set '%s' attributes other than - empno,empname,designation,empstatus"%(name))
            return 0
           
    def __getattr__(self, name):
        try:
            if not(name=="empno" or name=="empname" or name=="designation" or name=="empstatus"):
                return "Attribute not found -- %s"%(name)
        except KeyError:
            raise AttributeError

e = Employee()       
print("welcome to the program set attribute and get attribute")
print("Enter the attributes to add to the Employee class")
print("Enter the number of attributes for the Employee class")
print("attributes should be same as in list - empno,empname,designation,empstatus")
lp = True
while(lp):
    a = input("enter the attribute name:")
    v = input("enter the attribute value:")
    valuestatus=setattr(e, a, v)
    if(valuestatus==0):
        print("attribute not added")
    a = input("enter the attribute name:")
    print(getattr(e,a))
    if input("do u want to continue:y/n - ")=='n':
        break
print("List of attributes are added")
print(e.__dict__)


