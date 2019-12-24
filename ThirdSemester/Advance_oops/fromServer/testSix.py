from tkinter import *
import tkinter.messagebox as tm


window = Tk()
window.title("Login Form")
window.geometry("400x400")

username = "aditya"
password = "123"

idvar = StringVar()
passvar = StringVar()

idvar.set('')
passvar.set('')


def onclick():
    if (idvar.get() == username and passvar.get() == password):
        tm.showinfo("Login Alert", "Successful logged '%s' " % (username))
    else:
        tm.showerror("Login Alert", "INVALID")


def clear():
    idvar.set('')
    passvar.set('')


name = Label(window, text="User Name").grid(row=0, column=2)
nameEntry = Entry(window, textvariable=idvar).grid(row=0, column=6)

passw = Label(window, text="Password").grid(row=1, column=2)
passEntry = Entry(window, textvariable=passvar, show="*").grid(row=1, column=6)

sub = Button(window, text="SUBMIT", command=onclick).grid(row=6, column=1)
cle = Button(window, text="CLEAR", command=clear).grid(row=6, column=2)
exe = Button(window, text="EXIT", command=window.destroy).grid(row=6, column=3)
window.mainloop()
