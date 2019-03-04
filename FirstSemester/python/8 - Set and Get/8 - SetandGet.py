class Employee(object):
   
    def __setattr__(self, name, value):
        if name=="empno" or name=="empname" or name=="designation" or name=="empstatus":
            self.__dict__[name] = value
            print("value set for %s -- %s"%(name,value)) # print("value set is ",name,value)
            print("--"*60)
        else:
            print("cannot set '%s' attributes other than - empno,empname,designation,empstatus"%(name))
            return 0
           
    def __getattr__(self, name):
            if (name=="empno" or name=="empname" or name=="designation" or name=="empstatus"):
                return "No value assign yet"
            if not(name == "empno" or name == "empname" or name == "designation" or name == "empstatus"):
                return "Attribute not found -- %s" % (name)
            
        

e = Employee() 

while True:
    print("1-Setting value to employee ")  # setter
    print("2-Enter more details ") 
    print("3-Getting value from employee ") # getter
    print("4-Add employee details to dictionary ")
    ch = int(input("Enter choice : "))
    print("--"*60)
    if ch==1 or ch==2:
        print("--"*60)
        print("Take attribute as |empno|--|empname|--|designation|--|empstatus|")
        a = input("enter the attribute name: ")
        v = input("enter the attribute value: ")
        flag=setattr(e, a, v)
        if(flag==0):
            print("attribute not added ")
    elif ch == 3:
        print("--"*60)
        print("Search employee attribute : ")
        print("Take attribute name as |empno|--|empname|--|designation|--|empstatus|")
        a = input("enter the attribute name: ")
        print(getattr(e, a))
        print("--"*60)
    elif ch==4:
        print("--"*60)
        print("List of attributes are added ")
        print(e.__dict__)   
        print("--"*60)


        
    



