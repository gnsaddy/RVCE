class Test:
    def __init__(self):
        self.lst=[]

    def geter(self):
        n = int(input("\nEnter list size\n"))
        for i in range(0,n):
            item = int(input("Enter list element"))
            self.lst.append(item)
        return self.lst

    def __add__(self, other):
        new_list = []
        for i in range(0, len(self.alist)):
            new_list.append(self.alist[i]+other.alist[i])
        return new_list
