from tkinter import *

top = Tk()
top.title("Conversion Table")
top.geometry("600x300")

val = DoubleVar()
val.set('')

val2 = DoubleVar()
val2.set('')

val3 = DoubleVar()
val3.set('')

val4 = DoubleVar()
val4.set('')

fout = DoubleVar()
fout.set('')

def GConversion():
        fout.set(val.get()*0.03527)
def KConversion():
        fout.set(val2.get()*2.204)

def SConversion():
        fout.set(val3.get()*2.204)
def FConversion():
        fout.set(val4.get()*1.8+32)
def clear():
        fout.set('')
        val.set('')
        val2.set('')
        val3.set('')
        val4.set('')


l1 = Label(top,text = "Gram Value").grid(row = 1,column=0,padx=30,pady=20)
gram = Entry(top,textvariable = val).grid(row = 1,column = 1,ipadx = 10)

ounce = Button(top,text="Ounce",command = GConversion).grid(row = 1,column=2)
 

l2 = Label(top,text = "Kilo Value").grid(row = 2,column=0,padx=30,pady=20)
kilo = Entry(top,textvariable = val2).grid(row = 2,column = 1,ipadx = 10)

pound = Button(top,text="Pounds",command = KConversion).grid(row = 2,column=2)


l3 = Label(top,text = "Ahr").grid(row = 3,column=0,padx=30,pady=20)
ahr = Entry(top,textvariable = val3).grid(row = 3,column = 1,ipadx = 10)

stone = Button(top,text="Stone",command = SConversion).grid(row = 3,column=2)

l4 = Label(top,text = "Celsius").grid(row = 4,column=0,padx=30,pady=20)
Cel = Entry(top,textvariable = val4).grid(row = 4,column = 1,ipadx = 10)

Fah = Button(top,text="Fahrenheit",command = FConversion).grid(row = 4,column=2)

l5 = Label(top,text="Output").grid(row = 5,column=0,padx=20,pady=10)

l6 = Label(top,textvariable = fout).grid(row=5,column=1,padx=20,pady=10)

bclear = Button(top,text="Clear",command = clear).grid(row=5,column=3,padx=20)
top.mainloop()

