import MySQLdb as md


class Student:
    global con, cur
    con = md.connect(host="localhost", user="root",
                     passwd="", database="testPyMysql")
    cur = con.cursor()

    def insert(self, usn, name, age, email, contact, address):
        exe = cur.execute('''INSERT INTO student VALUES('%s','%s',%d,'%s','%s','%s')''' % (
            usn, name, int(age), email, contact, address))
        print(exe)
        if exe == 0:
            print("Not inserted")
        else:
            print("Record Inserted!!!")
        con.commit()

    def display(self):
        v = cur.execute("select * from student")
        # print(cur.fetchall())
        fet = cur.fetchall()
        for r in fet:
            print(r)
        if v == 0:
            print("Empty record")

    def update(self, *args):
        exe = cur.execute(
            '''UPDATE student set address = '%s' where usn = '%s' ''' % (address, usn))
        print(exe)
        if exe == 0:
            print("Not updated")
        else:
            print("Updated successfull!!")
        con.commit()

    def delete(self, usn):
        exe = cur.execute('''delete from student where usn = '%s' ''' % (usn))
        if exe == 0:
            print("Not deleted ")
        else:
            print("Record with usn : '%s' deleted " % (usn))
        con.commit()

    def close(self):
        cur.close()
        con.close()


obj = Student()

while True:
    print("1-INSERT\n2-DISPLAY\n3-Update\n4-Delete\n5-Exit")
    ch = int(input("Enter choice :- "))
    if ch == 1:
        usn = input("Enter  USN :")
        name = input("Enter name : ")
        age = int(input("Enter Age : "))
        email = input("Enter email : ")
        contact = input("Enter contact : ")
        address = input("Enter Address : ")
        obj.insert(usn, name, age, email, contact, address)

    elif ch == 2:
        obj.display()
    elif ch == 3:
        usn = input("Enter USN : ")
        address = input("Enter address : ")
        obj.update(usn, address)
    elif ch == 4:
        usn = input("Enter usn : ")
        obj.delete(usn)
    elif ch == 5:
        obj.close()
        break
