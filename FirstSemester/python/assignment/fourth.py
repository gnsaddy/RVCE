data1 = {'a':1,'b':2,'c':3}
print(data1)
# OR
data2 = dict(a=1, b=2, c=3,d=4,e=5)
print(data2)
# OR
data3 = {k: v for k, v in (('a', 1),('b',2))}
print(data3)

data1['z'] = 1  # Updates if 'a' exists, else adds 'a'
print(data1)
# OR
data2.update({'a': 1})
print(data2)
# OR
data2.update(dict(x=5))
print(data2)
# OR
data2.update(z=5)
print(data2)
data3.update({'c': 3, 'd': 4})  # Updates 'c' and adds 'd'
print(data3)
