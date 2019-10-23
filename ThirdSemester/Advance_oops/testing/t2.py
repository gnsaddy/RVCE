from abc import ABC, abstractmethod, ABCMeta


class A(ABC):
    @abstractmethod
    def inner1(self):
        pass

    @abstractmethod
    def inner2(self):
        pass

class B(A):
    def inner1(self):
        print("From inner 1")

    def inner2(self):
        print("From inner 2")
        


obj = B()
obj.inner1()
obj.inner2()
