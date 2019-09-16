import time


def calculate_time(func):
    def inner1():
        begin = time.time()
        f = func()
        end = time.time()
        print("Total time taken in : ", func.__name__, end - begin)
        return f
    return inner1


@calculate_time
def fib():
    a, b = 0, 1
    while True:
        a, b = b, a + b
        yield a


g = fib()
print("\nUsing for in loop")
num = int(input("Enter number:- "))
for i in range(num):
    print(next(g))
