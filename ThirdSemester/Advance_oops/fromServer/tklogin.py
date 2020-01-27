from tkinter import *
from tkinter import messagebox
import MySQLdb as ms

top = Tk(className="LOGIN FORM")
top.geometry("400x300")

uvar = StringVar()
pvar = StringVar()
uvar.set("")
pvar.set("")


def click():
    con = ms.connect('localhost', 'root', '', 'testpymysql')
    cur = con.cursor()
    exe = cur.execute('''select * from admin where userid='%s' and password='%s' ''' %
                      (uvar.get(), pvar.get()))
    print(cur.fetchall())

    if exe == 1:
        messagebox.showinfo("Alert", "Authorized user")
    else:
        messagebox.showinfo("Alert", "Unauthorized user")


def Clear():
    uvar.set("")
    pvar.set("")


ulabel = Label(top, text="User name").grid(row=0, column=0)
uentry = Entry(top, textvariable=uvar).grid(row=0, column=3)
plabel = Label(top, text="Password").grid(row=1, column=0)
pentry = Entry(top, textvariable=pvar, show='*').grid(row=1, column=3)
b1 = Button(top, text="Submit", command=click).grid(row=3, column=0)
b2 = Button(top, text="Cancel", command=Clear).grid(row=3, column=2)
b3 = Button(top, text="Exit", command=top.destroy).grid(row=3, column=4)

top.mainloop()
