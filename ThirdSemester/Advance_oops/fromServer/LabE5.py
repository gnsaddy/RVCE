import MySQLdb as my
class Employee:
	db = my.connect('172.16.34.130','1rv18mca07','1rv18mca07','1rv18mca07')
	cur = db.cursor()

	def add(self,slno,name,address,empcode,dob,age,mobile,status,designation):
		v = self.cur.execute('''Insert into Emp values(%d,'%s','%s','%s',%d,%d,%d,'%s','%s')'''%(int(slno),name,address,empcode,int(dob),int(age),int(mobile),status,designation))
		print("Record inserted!")

	def display(self):
		self.cur.execute("select * from Emp")
		print(self.cur.fetchall())

	def delete(self,sln):
		self.cur.execute("Delete from Emp where slno=%d"%(int(sln)))
		print("Deleted successfully!")

	def update(self,stat,sln):
		self.cur.execute('''Update Emp set status='%s' where slno=%d'''%(stat,int(sln)))
		print("Updated successfully!")

	def closecon(self):
		self.cur.close()
		self.db.close()
e = Employee()
while True:
	print("1.Insert 2.Delete 3.Update 4.Display 5.Exit")
	ch = int(input("Enter choice : "))
	if ch==1:
		slno = int(input("Enter slno "))
		name = input("Enter name")
		address = input("Enter address")
		empcode = input("Enter empcode")
		dob = int(input("Enter dob"))
		age= int(input("Enter age "))
		mobile = int(input("Enter mobile "))
		status = input("Enter status ")
		designation = input("Enter designation ")
		e.add(slno,name,address,empcode,dob,age,mobile,status,designation)

	elif ch==2:
		sln = int(input("Enter slno to delete record : "))
		e.delete(sln)

	elif ch==3:
		stat = input("Enter new status to update : ")
		sln = int(input("Enter slno :"))
		e.update(stat,sln)
	elif ch==4:
		e.display()
	elif ch==5:
		e.closecon()
		break



