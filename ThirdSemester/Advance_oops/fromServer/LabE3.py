def details(value=False):
    if value == True:
        keys = ['empid', 'empname', 'empadd']

    else:
        keys = ['cmpid', 'cmpname', 'cmpadd']

    def init(self, **kwargs):
        self.expected_keys = set(keys)
        if self.expected_keys != set(kwargs.keys()):
            raise ValueError("Key don't match")
        else:
            for k, v in kwargs.items():
                setattr(self, k, v)

    if value:
        return type('emp', (object,), {'__init__': init, })
    else:
        return type('comp', (object,), {'__init__': init, })


emp = details(True)
e1 = emp(empid='101', empname='ABC', empadd='Bengalore')
print(type(emp))
print(type(e1))
print(e1.empid)

comp = details(False)
c1 = comp(cmpid='c1', cmpname='XYZ', cmpadd='Bengalore')
print(type(comp))
print(type(c1))
print(c1.cmpid)
