import abc
class Calculation(abc.ABC):
        def __init__(self,a,b):
                self.a = a
                self.b = b

        @abc.abstractmethod
        def calculate(self):
                pass
class Addition(Calculation):
        def calculate(self):
                sum = []
                for i in range(0,len(self.a)):
                        sum.append(self.a[i]+self.b[i])
                #map(lambda x,y:sum.append(x+y),self.a,self.b)
                print("Sum of ",self.a," and ",self.b," is ",sum)

class Subtraction(Calculation):
        def calculate(self):
                diff = []
                for i in range(0,len(self.a)):
                        diff.append(self.a[i]-self.b[i])
                print("Difference of ",self.a," and ",self.b," is ",diff)

class Multiplication(Calculation):
        def calculate(self):
                prod = []
                for i in range(0,len(self.a)):
                        prod.append(self.a[i]*self.b[i])
                print("Product of ",self.a," and ",self.b," is ",prod)

class Division(Calculation):
        def calculate(self):
                quot = []
                for i in range(0,len(self.a)):
                        quot.append(self.a[i]/self.b[i])
                print("Quotient of ",self.a," and ",self.b," is ",quot)


l = int(input("Enter number of elements in list : "))
p = []
q = []
print("Enter list1 ")
for i in range(0,l):
        p.append(int(input()))
print("Enter list2 ")
for i in range(0,l):
        q.append(int(input()))
print("List 1 : ",p," \t List 2 : ",q)
while(True):
        print("*******Operations********   \n1.Addition \n2.Subtraction \n3.Mul$
        ch = int(input("Enter choice : "))
        if ch==1:
                Addition(p,q).calculate()

        elif ch==2:
                Subtraction(p,q).calculate()

        elif ch==3:
                Multiplication(p,q).calculate()

        elif ch==4:
	        Division(p,q).calculate()

        elif ch==5:
                exit()
        else:
                print("Invalid choice!")



