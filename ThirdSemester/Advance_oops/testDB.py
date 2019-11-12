import pymysql as psq

con = psq.connect(host="localhost",user="root",passwd="",database="testPyMysql")
cursor = con.cursor()


studentTbl = ''' CREATE TABLE student(usn varchar(30) primary key,name varchar(30) not null,age int(5))'''
cursor.execute(studentTbl)
insert1 = "INSERT into student values('1RD18MCA01','Aditya',21)"
insert2 = "INSERT into student values('1RD18MCA02','Akash',21)"


#executing the quires
cursor.execute(insert1)
cursor.execute(insert2)

### queries for retrievint all rows
retrive = "Select * from student;"

#executing the quires
cursor.execute(retrive)
rows = cursor.fetchall()
for row in rows:
  print(row)


updateSql = "UPDATE  student SET name= 'Ajith'  WHERE usn = '1RD18MCA02' ;"
cursor.execute(updateSql)

# queries for retrievint all rows
retrive = "Select * from student;"

cursor.execute("select name from student where usn= '1RD18MCA01' ")
print(cursor.fetchone())

#executing the quires
cursor.execute(retrive)
rows = cursor.fetchall()
for row in rows:
  print(row)

deleteSql = "DELETE FROM student WHERE usn = '1RD18MCA02'; "
cursor.execute(deleteSql )

# queries for retrievint all rows
retrive = "Select * from student;"

#executing the quires
cursor.execute(retrive)
rows = cursor.fetchall()
for row in rows:
  print(row)

dropSql = "DROP TABLE IF EXISTS student;"
cursor.execute(dropSql)
#commiting the connection then closing it.
con.commit()
