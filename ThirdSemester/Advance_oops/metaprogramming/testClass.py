class TestClass:
    pass


test_obj = TestClass()
print(test_obj)


print(type(TestClass))
type(type)

print("------------------------------")


class DemoTest():
    pass


DemoTestClass = type('DemoTest', (), {})
print(DemoTestClass)
type(DemoTest)
type(DemoTestClass)
print(DemoTest())
demoTest_obj = DemoTest()
print(demoTest_obj)

print("------------------------------")

PythonCoding = type('PythonCoding', (), {'Name': 'Aditya', 'Hobby': 'Coding'})
type(PythonCoding)
print(PythonCoding.Name, " ", PythonCoding.Hobby)
print(PythonCoding)


class TestMeta(type):
    def __new__(cls, clsname, superclasses, attributedict):
        print("clsname: ", clsname)
        print("superclasses: ", superclasses)
        print("attributedict: ", attributedict)
        return type.__new__(cls, clsname, superclasses, attributedict)


PythonCodingT = type('PythonCodingT', (DemoTest,), {
                     'Name': 'Aditya', 'Hobby': 'Coding'})
type(PythonCodingT)
print(PythonCodingT.Name)


class B(PythonCodingT, metaclass=TestMeta):
    pass


print('------------------------------------------')


class LittleMeta(type):
    def __new__(cls, clsname, superclasses, attributedict):
        print("clsname: ", clsname)
        print("superclasses: ", superclasses)
        print("attributedict: ", attributedict)
        return type.__new__(cls, clsname, superclasses, attributedict)


class S:
    pass


class A(S, metaclass=LittleMeta):
    pass


a = A()

print(type(LittleMeta))
