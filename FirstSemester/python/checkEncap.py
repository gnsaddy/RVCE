class Check:
    name = ""
    age = 0

    def getter(self):
        self.name=input("Enter name")
        self.age=int(input("Enter age"))

    def disp(self):
        print(self.name)
        print(self.age)


obj=Check()
obj.getter()
obj.disp()
