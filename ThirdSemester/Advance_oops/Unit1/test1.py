def star(func):
    def inner():
        print("*" * 30)
        func()
        print("*" * 30)
    return inner


def dash(func):
    def inner():
        print("-" * 30)
        func()
        print("-" * 30)
    return inner


@star
@dash
def showBetween():
    print("From the function ")


showBetween()
