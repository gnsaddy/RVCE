from tkinter import *
def movement():
        canvas.move("car",2,0)
        canvas.after(100,movement)

root = Tk()
root.geometry("700x700")

canvas = Canvas(root)
rec = canvas.create_rectangle(150,150,320,200,tags="car")

l1 = canvas.create_line(150,150,200,120,tags="car")
l2 = canvas.create_line(200,120,280,120,tags="car")
l3 = canvas.create_line(280,120,320,150,tags="car")

c1 = canvas.create_oval(180,200,200,220,tags="car")
c2 = canvas.create_oval(300,200,320,220,tags="car")

l4 = canvas.create_line(320,150,375,170,tags="car")
l5 = canvas.create_line(375,170,375,200,tags="car")

l6 = canvas.create_line(320,200,375,200,tags="car")
canvas.pack()
movement()
mainloop()
