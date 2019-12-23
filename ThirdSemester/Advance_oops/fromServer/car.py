from tkinter import *


def movement():
    Canvas.move("car", 5, 0)
    Canvas.after(100, movement)


master = Tk()
Canvas = Canvas(master)
rec = Canvas.create_rectangle(40, 100, 320, 200, fill="red", tag="car")
line = Canvas.create_line(100, 40, 200, 40, tag="car")
l1 = Canvas.create_line(100, 40, 80, 100, tag="car")
l1 = Canvas.create_line(200, 40, 200, 100, tag="car")
l1 = Canvas.create_line(200, 40, 280, 100, tag="car")
c1 = Canvas.create_oval(70, 180, 110, 220, tag="car", fill="black")
c1 = Canvas.create_oval(270, 180, 310, 220, tag="car", fill="black")
l1 = Canvas.create_oval(35, 100, 40, 120, tag="car")
l1 = Canvas.create_oval(319, 100, 340, 120, tag="car")

movement()
Canvas.pack()
master.mainloop()
