class File():
    def __init__(self, name, mode):
        self.file = open(name, mode)

    def __enter__(self):
        print('The file will be returned.')
        return self.file

    def __exit__(self, type, value, traceback):
        print('The file will be closed now.')
        self.file.close()
        return True


with File('testfile.txt', 'w') as myfile:
    myfile.write('Hello world!')
