import MySQLdb as md

class Student:
    global con, cur
    con = md.connect("localhost","root","","testPyMysql")
    cur = con.cursor()
    
    def insert(self,usn,name,age,ph,addr):
        ex = cur.execute(''' INSERT INTO stu VALUES('%s','%s',%d,'%s','%s')''' %(usn,name,int(age),ph,addr))
        if ex == 0:
            print("Failed")
        else:
            print("Inserted")
            
        con.commit()
        
    def display(self):
        ex = cur.execute("select * from stu")
        ft = cur.fetchall()
        for i in ft:
            print(i)
            
        if ex == 0:
            print("No record found")
            
            
    def update(self,usn,addr):
        ex = cur.execute(''' update stu set addr= '%s' where usn='%s' ''' %(addr,usn))
        if ex == 1:
            print("Updated")
        else:
            print("Not updated")
        con.commit()
        
    def delete(self,usn):
        ex = cur.execute(''' delete from stu where usn = '%s' ''' %(usn))
        if ex == 1:
            print("Deleted ")
        else:
            print("Not deleted")
        con.commit()
            
            


obj = Student()

while True:
    print("1-INSERT\n2-DISPLAY\n3-Update\n4-Delete\n5-Exit")
    ch = int(input("Enter choice :- "))
    if ch == 1:
        usn = input("Enter  USN :")
        name = input("Enter name : ")
        age = int(input("Enter Age : "))
        ph = input("Enter contact : ")
        addr = input("Enter Address : ")
        obj.insert(usn, name, age, ph, addr)

    elif ch == 2:
        obj.display()
        
    elif ch == 3:
        usn = input("Enter usn : ")
        addr = input("Enter address : ")
        obj.update(usn,addr)
        
    elif ch == 4:
        usn = input("Enter usn : ")
        obj.delete(usn)