from tkinter import *
from tkinter import ttk
 
root = Tk()     # создаем корневой объект - окно
root.title("Приложение на Tkinter")     # устанавливаем заголовок окна
root.geometry("800x800")    # устанавливаем размеры окна
 
def click_button():
    mas.append([int(x_0.get()),int(y_0.get()), int(x_1.get()),int(y_1.get())])
    canvas.create_rectangle(int(x_0.get()),int(y_0.get()), int(x_1.get()),int(y_1.get()), fill="black")
    canvas.create_oval(int(x_0.get())-3,int(y_0.get())-3, int(x_0.get())+3,int(y_0.get())+3, fill="red")
    canvas.create_oval(int(x_1.get())-3,int(y_0.get())-3, int(x_1.get())+3,int(y_0.get())+3, fill="red")
    canvas.create_oval(int(x_0.get())-3,int(y_1.get())-3, int(x_0.get())+3,int(y_1.get())+3, fill="red")
    canvas.create_oval(int(x_1.get())-3,int(y_1.get())-3, int(x_1.get())+3,int(y_1.get())+3, fill="red")

# label = Label(text="Hello METANIT.COM") # создаем текстовую метку
# label.pack()    # размещаем метку в окне

canvas = Canvas(bg="white", width=600, height=800)
canvas.pack(anchor="nw", expand=1)
##############
x_0 = ttk.Entry(width=10)
x_0.place(x=620, y=20, width=120, height=20)
y_0 = ttk.Entry(width=10)
y_0.place(x=620, y=50, width=120, height=20)

x_1 = ttk.Entry(width=10)
x_1.place(x=620, y=80, width=120, height=20)
y_1 = ttk.Entry(width=10)
y_1.place(x=620, y=110, width=120, height=20)
##############

mas = []

# btn = ttk.Button(text="Click") # создаем кнопку из пакета ttk
btn = ttk.Button(text="Click Me", command=click_button)
btn.place(x=620, y=140, width=120, height=20)    # размещаем кнопку в окне

def move_rect(event):
    canvas.coords(t, event.x - 50, event.y - 50, event.x + 50, event.y + 50)

canvas.bind('<1>', move_rect)

root.mainloop()