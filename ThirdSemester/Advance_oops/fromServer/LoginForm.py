from tkinter import *
import tkinter.messagebox as tm
class LoginPage(Frame):

        def loginclicked(self):
                user = self.user.get()  
                password = self.password.get()
                if user == "abc" and password == "123":
                        tm.showinfo("Logged In","Welcome!")
                else:
                        tm.showerror("Error","Invalid username or password!")

        def cancelclicked(self):
                self.uid.set("")
                self.pid.set("")

        def __init__(self,master):
                super().__init__(master)

                self.uid = StringVar()
                self.pid = StringVar()

                self.l1 = Label(self,text="Username")
                self.l2 = Label(self,text="Password")

                self.user = Entry(self,textvariable = self.uid)
                self.password = Entry(self,textvariable = self.pid,show="*")

                self.l1.grid(row=0,sticky=E)
                self.l2.grid(row=1,sticky=E)

                self.user.grid(row=0,column=1)
                self.password.grid(row=1,column=1)

                self.pack()
                self.loginbtn = Button(self,text="OK",command= self.loginclicked).grid(row=2,column=1)

                self.cancelbtn = Button(self,text="Cancel",command= self.cancelclicked).grid(row=2,column=2)

window = Tk()
e = LoginPage(window)
window.title("Login Form")
window.geometry("300x200")
window.mainloop()

