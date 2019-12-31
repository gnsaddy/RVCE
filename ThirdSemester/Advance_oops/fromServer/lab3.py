def Take(ed = False):
    if ed:
        keys = ['eid','ename','eadd']
    else:
        keys = ['cid','cname','cadd']
        
    def init(self,*args,**kwargs):
        self.exp_keys = set(keys)
        print(self.exp_keys)
        
        
        if (self.exp_keys != set(kwargs.keys())):
            raise ValueError("key not found")
        else:
            for k,v in kwargs.items():
                setattr(self,k,v)
                
    if True:
        return type('Emp',(object,),{
                '__doc__':'Employee class',
                '__init__':init,
                })
                
    else:
        return type('cmp',(object,),{
                '__doc__':'Company class',
                '__init__':init,
                })              
                
emp = Take(True)
e1 = emp(eid='123',ename='aditya',eadd='bangalore')
print(e1.__doc__)
print(e1.__init__)
d = {'eid':e1.eid,'ename':e1.ename,'eadd':e1.eadd}
with open("l3.txt","a+") as fp:
    fp.write(str(d))
print(e1.eid)

cmp = Take()
c1 = cmp(cid='c123',cname='Bhaskar',cadd='delhi')
print(c1.__doc__)
print(c1.cid)
#print(help(cmp))


