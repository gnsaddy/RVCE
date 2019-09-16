def fib():
    a, b = 0, 1
    while True:
        a, b = b, a + b
        yield a


g = fib()
print("\nUsing for in loop")
for i in range(10):
    print(g.__next__())
