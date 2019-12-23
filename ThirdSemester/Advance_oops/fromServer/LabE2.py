# meta class Example
class Example(type):
    def __new__(cls, name, bases, dic):
        print("New method of ", name)
        print(cls)
        print(bases)
        print(dic)
        return super(Example, cls).__new__(cls, name, bases, dic)

    def __init__(cls, name, bases, dic):
        print("Init method of ", name)
        print(cls)
        print(bases)
        print(dic)
        return super(Example, cls).__init__(name, bases, dic)


class MyKlass(metaclass=Example):
    atr = 2

    def foo(self, param):
        print("Parameter of foo ", param)


m = MyKlass()
m.foo("hello")
