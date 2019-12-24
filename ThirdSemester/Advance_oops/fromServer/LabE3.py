
def Comp_Emp(et=False):
        if(et == True):
                keys = ['empid','ename','empaddress']
        else:
                keys = ['compid','cname','caddress']

        class Credential:
                exp_keys = set(keys)

                def __init__(self,**kwargs):
                        if self.exp_keys != set(kwargs.keys()):
                                raise KeyError
                        else:
                                for k,v in kwargs.items():
                                        setattr(self, k, v)
        return Credential


Emp = Comp_Emp(True)
#help(Emp)
e1 = Emp(empid='e01',ename='Ishaani',empaddress='bengaluru')
#help(e1)
print(type(Emp))
print(type(e1))
print("\n")

Comp = Comp_Emp(False)
c1 = Comp(compid = 'c01',cname = 'Cerner',caddress = 'HSR')
print(type(Comp))
print(type(c1))

