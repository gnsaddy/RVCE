from tkinter import messagebox
from tkinter import *
import tkinter
import pymysql as psql
# ==============================METHODS========================================
##### LAB TKINTER ############

top = tkinter.Tk(className="LOGIN FORM")
top.geometry("400x300")
userid = StringVar()
password = StringVar()


def click():
    # Database()

    con = psql.connect(host="localhost", user="root",
                       passwd="", database="testPyMysql")

    cursor = con.cursor()
    # adminTBL = ''' CREATE TABLE admin(userid varchar(30) primary key, password varchar(30) not null)'''
    # cursor.execute(adminTBL)
    cursor.execute(
        "SELECT * FROM `admin` WHERE `userid` = 'admin' AND `password` = 'admin'")
    if cursor.fetchone() is None:
        cursor.execute(
            "INSERT INTO `admin` (`userid`, `password`) VALUES('admin', 'admin')")
        con.commit()

    if(userid.get() == "" and password.get() == ""):
        messagebox.showinfo("Alert", "Please complete the required field!")
    else:
        findUser = (
            "SELECT * FROM `admin` WHERE `userid` = ? AND `password` = ? ")
        cursor.execute(findUser, [userid.get(), password.get()])

        if cursor.fetchall() is not None:
            userid.set("")
            password.set("")
            messagebox.showinfo("Alert", "Authorized user")

        else:
            messagebox.showinfo("Alert", "Please give valid id & password")
            userid.set("")
            password.set("")
    cursor.close()
    con.close()


def Clear():
    userid.set("")
    password.set("")
    uentry.focus()


ulabel = tkinter.Label(top, text="User name")
uentry = tkinter.Entry(top, textvariable=userid)
plabel = tkinter.Label(top, text="Password")
pentry = tkinter.Entry(top, textvariable=password)
b1 = tkinter.Button(top, text="Submit", command=click)
b2 = tkinter.Button(top, text="Cancel", command=Clear)
b3 = tkinter.Button(top, text="Exit", command=top.destroy)

# geometry manager
ulabel.grid(row=0, column=0)
uentry.grid(row=0, column=3)
plabel.grid(row=1, column=0)
pentry.grid(row=1, column=3)
b1.grid(row=3, column=0)
b2.grid(row=3, column=2)
b3.grid(row=3, column=4)
tkinter.mainloop()
