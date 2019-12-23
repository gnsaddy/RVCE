import tkinter as tk
root = tk.Tk()
var = tk.StringVar()
root.geometry("200x200")

max_len = 5

''' Define a trace callback for the variable.

MODE is one of "r", "w", "u" for read, write, undefined. CALLBACK must be a function which is called when the variable is read, written or undefined.

Return the name of the callback.'''


def on_write(*args):
    s = var.get()
    if len(s) > max_len:
        var.set(s[:max_len])


# w as read while on_write
# var is the name of text-variable or the text box which we defined
# var.trace_variable takes argument w:write mode and second the callback call return
# declare var Entry
var.trace_variable("w", on_write)
entry = tk.Entry(root, textvariable=var)
entry.pack()
root.mainloop()
