# importing libraries
import time


def calculate_time(func):
    begin = time.time()
    func()
    end = time.time()
    print("Total time taken by : ", func.__name__, "() is :", (end - begin))
    return func


class Fibs:
    def __init__(self):
        self.a = 0
        self.b = 1

    def __next__(self):
        self.a, self.b = self.b, self.a + self.b
        return self.a

    def __iter__(self):
        return self


@calculate_time
def execute():
    fib = Fibs()
    n = int(input("Enter number:- "))
    for f in range(n):
        print(next(fib))
