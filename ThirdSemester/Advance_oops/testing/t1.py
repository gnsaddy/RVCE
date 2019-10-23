

def f0(func):
    def inner(*args, **kwargs):
        print("from deco------------------")
        c = func()
        print("deco 2---------------------")

    return inner


def f1(func):
    def inner(*args, **kwargs):
        print("from deco ********************@@@@@@@@@@@@@@@@@@@@@")
        c = func()
        print("deco 2 ********************")

    return inner


@f0
@f1
def f2():
    print("Hello")


f2()
