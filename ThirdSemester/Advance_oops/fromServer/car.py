from tkinter import *

x = 0
def movement():
    global x
    x = x+1
    if(x==15):
        mov2()
    Canvas.move("car", 5, 0)
    Canvas.after(50, movement)

def mov2():
    Canvas.move("car",-6,0)
    Canvas.after(50,mov2)
    if x == 15:
        Canvas.move("car", -50, 0)
        Canvas.after(50, movement)

master = Tk()
Canvas = Canvas(master,width="1400",height="1400")
master.geometry("1400x1400")
rec = Canvas.create_rectangle(40, 100, 320, 200, fill="red", tag="car")
line = Canvas.create_line(100, 40, 200, 40, tag="car")
l1 = Canvas.create_line(100, 40, 80, 100, tag="car")
l2 = Canvas.create_line(200, 40, 200, 100, tag="car")
l3 = Canvas.create_line(200, 40, 280, 100, tag="car")
c1 = Canvas.create_oval(70, 180, 110, 220, tag="car", fill="black")
c2 = Canvas.create_oval(270, 180, 310, 220, tag="car", fill="black")
l4 = Canvas.create_oval(35, 100, 40, 120, tag="car")
l5 = Canvas.create_oval(319, 100, 340, 120, tag="car")

movement()
Canvas.pack()
master.mainloop()
