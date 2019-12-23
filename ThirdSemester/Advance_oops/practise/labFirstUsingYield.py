import time


def calculate_time(func):
    def inner1():
        begin = time.time()
        f = func()
        end = time.time()
        print("Total time taken in : ", func.__name__, end - begin)
        minus, sec = divmod((end - begin), 60)
        print("minutes ", minus, "\n Seconds ", sec)
        return f
    return inner1


def fib():
    a, b = 0, 1
    while True:
        a, b = b, a + b
        yield a


@calculate_time
def findFib():
    g = fib()
    print("\nUsing for in loop")
    num = int(input("Enter number:- "))
    for i in range(num):
        print(next(g))


findFib()
