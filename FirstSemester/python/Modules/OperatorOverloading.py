class opeover:
    def __init__(self):
        self.alist=[]
    def get_element(self):
        n=int(input("\nEnter list size\n"))
        for i in range(0,n):
            item=int(input("Enter list element "))
            self.alist.append(item)
        return self.alist
    def __add__(self,other):
        new_list = []
        for i in range(0,len(self.alist)):
            new_list.append(self.alist[i]+other.alist[i])
        return new_list
         
    def __sub__(self,other):
        new_list = []
        for i in range(0,len(self.alist)):
            new_list.append(self.alist[i]-other.alist[i])
        return new_list 
    def __mul__(self,other):
        new_list = []
        for i in range(0,len(self.alist)):
            new_list.append(self.alist[i]*other.alist[i])
        return new_list
    
    def __floordiv__(self,other):
        new_list = []
        for i in range(0,len(self.alist)):
            new_list.append(self.alist[i]//other.alist[i])
        return new_list
