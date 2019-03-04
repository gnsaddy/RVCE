class Calc():
    def sum(self,n1,n2):
        print("sum ",(n1+n2))

    def sub(self, n1, n2):
        print("sub ", (n1-n2))

    def mul(self, n1, n2):
        print("mul ", (n1*n2))

    def div(self, n1, n2):
        print("div ", (n1/n2))
 
c1 = Calc()

while True:
    print("1-Add \n2-Sub \n3-Mul \n4-Div ")
    ch = int(input("Enter choice :"))
    f1 = int(input("Enter first :"))
    f2 = int(input("Ente second :"))
    
    if ch == 1:
        c1.sum(f1,f2)
    elif ch == 2:
        c1.sub(f1,f2)
    elif ch == 3:
        c1.mul(f1,f2)
    elif ch == 4:
        c1.div(f1,f2)
    elif ch > 4:
        break
