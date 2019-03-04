# Define a class as 'student'
class student:
    def __init__(self, USN=' ', name=' ', age=0):
        self.USN=USN
        self.name=name
        self.age=age
    def getStudent(self):
        self.name = input("Enter the Name: ")
        self.usn = input("Enter the USN: ")
        self.age = input("Enter the Age: ")
        self.gender = input("Enter the Gender: ")
        

# Define a class as 'test' and inherit base class 'student'
class Subject(student):
    def __init__(self, sem=0,Var1=0, Var2=0, Var3=0, Var4=0, Var5=0):
        self.Var1=Var1
        self.Var2=Var2
        self.Var3=Var3
        self.Var4=Var4
        self.Var5=Var5
        self.sem = sem
    # Method
    def getMarks(self):
        self.sem = input("Enter the Semester: ")
        print("Enter the marks of the respective subjects")
        self.subject= input("Enter the Subject Name ")
        self.Var1 = int(input("Enter the Marks of %s "%(self.subject)))
        self.subject= input("Enter the Subject Name ")
        self.Var2 = int(input("Enter the Marks of %s "%(self.subject)))
        self.subject= input("Enter the Subject Name ")
        self.Var3 = int(input("Enter the Marks of %s "%(self.subject)))
        self.subject= input("Enter the Subject Name ")
        self.Var4 = int(input("Enter the Marks of %s "%(self.subject)))
        self.subject= input("Enter the Subject Name ")
        self.Var5 = int(input("Enter the Marks of %s "%(self.subject)))

# Define a class as 'marks' and inherit derived class 'test'
class Results(Subject):
    # Method
    def display_Results(self):
        print("\n\nName: ",self.name)
        print("\n\nName: ",self.usn)
        print("Age: ",self.age)
        print("Gender: ",self.gender)
        print("Study in: ",self.sem)
        Total_Marks = self.Var1+self.Var2+self.Var3+self.Var4+self.Var5
        print("Total Marks: ",Total_Marks)
        self.percentage = ((Total_Marks/500)*100)
        print("Percentage of %s in Semester %s is %s Percent  "%(self.name,self.sem,self.percentage)) 


m1 = Results()
# Call base class method 'getStudent()'
m1.getStudent()
# Call first derived class method 'getMarks()'
m1.getMarks()
# Call second derived class method 'display()'
m1.display_Results()
