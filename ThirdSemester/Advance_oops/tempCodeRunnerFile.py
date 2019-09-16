import time
import math

def calculate_time(func):
    def inner1():
        begin = time.time()
        func()
        end = time.time()
        print("Total time taken in : ", func.__name__, end - begin)
    return inner1