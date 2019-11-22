from contextlib import ContextDecorator
import os.path as op


class mycontext(ContextDecorator):
    def __init__(self, name, mode):
        self.name = name
        self.mode = mode
        self.file = None

    def __enter__(self):
        self.file = open(self.name, self.mode)
        print('Starting')
        print("*"*20)
        return self.file

    def __exit__(self, *exc):
        print("*"*20)
        print('Finishing')
        self.file.close()
        return False


fileName = input("Enter file name : ")
while (True):
    print("\nFile operations \n")
    print("\n1.Create and write into file\n2.Read from file\n")
    ch = int(input("Enter choice : "))
    if ch == 1:
        if (op.exists(fileName)):
            print("File already exist")
            exit()
        with mycontext(fileName, 'w') as fp:
            fp.write(input("Write into file \n"))

    if ch == 2:
        if (op.exists(fileName)):
            with mycontext(fileName, 'r') as fp:
                data = fp.read()
                print(data)
        else:
            print("File not found")


print(fp.closed)
