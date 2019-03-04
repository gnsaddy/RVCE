# linear search using python

lst = [2,3,5,8,9,11,1]
def lin(item):
    for i in lst:
        print(i,lst)
        if item in lst:
            print("item found ",item)
            break
        elif item not in lst:
            print("item not found")
            break

item = int(input("Enter item to search "))
lin(item)

