class TestDemo(type):
    pass


TestingDemo = type('TT', (TestDemo,), {})

print(type(TestDemo))
print(type(TestingDemo))
print(TestDemo)
print(TestingDemo)

print(TestDemo == TestingDemo)
print(issubclass(TestingDemo, TestDemo))
