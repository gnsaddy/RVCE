# importing libraries
import time
import math


def calculate_time(func):
    def inner1():
        begin = time.time()
        f = func()
        end = time.time()
        print("Total time taken in : ", func.__name__, end - begin)
        return f
    return inner1


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
    # print(next(fib))


execute()
