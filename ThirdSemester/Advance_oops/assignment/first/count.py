from contextlib import ContextDecorator
class mycontext(ContextDecorator):
    def __init__(self, name):
        self.name = name

    def __enter__(self):
        self.file = open(self.name, 'r')
        print('Starting')
        print("*"*20)
        return self.file

    def __exit__(self, *exc):
        print("*"*20)
        print('Finishing')
        self.file.close()
        return False

with mycontext('test.txt') as f:
    data = f.read()
    print(data)
    numOfChars = len(data)
    numOfWords = len(data.split())
    numOfLines = len(data.splitlines())
    print("Number of charecter in test.txt file", numOfChars)
    print("Number of Words in test.txt file", numOfWords)
    print("Number of Lines in test.txt file=", numOfLines)

print(f.closed)
