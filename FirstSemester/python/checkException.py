print("Exception handling")


print("Divide by zero exception")

a=int(input("Enter first number "))
b = int(input("Enter second number "))

try:
    print(a/b)
except ZeroDivisionError:
    print("Divide by zero error change second number ")

finally:
    print("Do not use zero as second number")

