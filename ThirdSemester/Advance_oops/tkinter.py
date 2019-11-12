##### LAB TKINTER ############
import tkinter
from tkinter import *
from tkinter import messagebox

uname = "rvce"
Password = "12345"
top = tkinter.Tk(className="LOGIN FORM")
top.geometry("400x300")

uvar = StringVar()
pvar = StringVar()
uvar.set("")
pvar.set("")


def click():
    if(uvar.get() == uname and pvar.get() == Password):
        messagebox.showinfo("Alert", "Authorized user")
    else:
        messagebox.showinfo("Alert", "Unauthorized user")


def Clear():
    uvar.set("")
    pvar.set("")
    uentry.focus()


ulabel = tkinter.Label(top, text="User name")
uentry = tkinter.Entry(top, textvariable=uvar)
plabel = tkinter.Label(top, text="Password")
pentry = tkinter.Entry(top, textvariable=pvar)
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
