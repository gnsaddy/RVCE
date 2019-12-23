import time


def caltime(func):
    st = time.time()
    print("Start time is : ", st)
    func()
    et = time.time()
    print("\nEnd time is : ", et)
    d = et-st
    print("Total time taken to execute is  ", d)
    minus, sec = divmod(d, 60)
    print("minutes ", minus, "\n Seconds ", sec)
    return func


class Fibs:
    def __init__(self):
        self.a = 0
        self.b = 1

    def __next__(self):
        # print(self.a,end="\t")
        self.a, self.b = self.b, self.a+self.b
        return self.a

    def __iter__(self):
        return self


@caltime
def execute():
    fib = Fibs()
    n = int(input("Enter n value : "))
    for f in range(n-1):
        next(fib)

    print(next(fib))
