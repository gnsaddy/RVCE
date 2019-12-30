from abc import ABC, abstractmethod, ABCMeta


class Calculate(ABC):
    def __init__(self, a, b):
        self.a = a
        self.b = b

    @abstractmethod
    def find(self):
        pass


class AdditionList(Calculate):
    def find(self):
        sum = []
        for i in range(0, len(self.a)):
            sum.append(self.a[i] + self.b[i])

        print("sum is:- ", sum)


l = int(input("Entre number of elements in a list "))
p, q = [], []

print("Enter list 1")
for i in range(0, l):
    p.append(int(input()))

print("Enter list 2")
for i in range(0, l):
    q.append(int(input()))

print("list 1: ", p, "list 2: ", q)

AdditionList(p, q).find()
