s1 = input("Enter String : ")
s2 = input("Enter String : ")
s3 = s1+s2

def reverse():
    str1 = ""
    str2 = ""
    for i in s3:
        str1 = i + str1
    return str1
    

   
print("The original string  is : ", end="")
print(s1,s2)
print("-"*60)


print("The reversed string is : ", end="")
print(reverse())

    

