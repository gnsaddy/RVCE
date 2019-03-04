def fact(n):
    if n == 0:
        return 1
    return n*fact(n-1)

result = fact(5)
print(result)

def fib(x):
    if x == 0:
        return 0
    if x == 1:
        return 1
    else:
        return fib(x-1) + fib(x-2)


print("Fibonacci sequence:")
for i in range(10):
    print(fib(i))
