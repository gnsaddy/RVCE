def fun(a=20, b=40):
    return a+b


class TestMeta(type):

    def t():
        return "inside function"

    def __new__(cls, name, base, attr):
        print("Class name : ", name)
        print("Current executing object : ", cls)
        print("Super classes : ", base)
        attr['ExtraAttr:fun'] = fun()
        attr['new:t'] = TestMeta.t()
        print("Dictionaries attributes : ", attr)
        return super(TestMeta, cls).__new__(cls, name, base, attr)

    def __init__(cls, name, base, attr):
        print("Class name : ", name)
        print("Current executing object : ", cls)
        print("Super classes : ", base)
        print("Dictionaries attributes : ", attr)
        return super(TestMeta, cls).__init__(name, base, attr)


class Test(object, metaclass=TestMeta):
    attr = 40

    def foo(self, param):
        print("parameter passed is : ", param)


obj = Test()
obj.foo("Aditya")
