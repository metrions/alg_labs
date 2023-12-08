from tkinter import *
from tkinter import ttk
from tkinter.messagebox import showerror, showwarning, showinfo
import json
# import tk
 
root = Tk()     # создаем корневой объект - окно
root.title("Приложение на Tkinter")     # устанавливаем заголовок окна
root.geometry("800x800")    # устанавливаем размеры окна
 

mas = []
mas_rect = []       #массив всех
mas_ver = []        #массив всех вершин и пряпятствий и точек 
mas_lines = []      #массив всех граней препятствий 
rect = []
tochk = []

start = []          #точка начала
end = []            #точка конца
edges = []          #множество ребер
vertices = set()    #множество вершин

#пересекаются ли отрезки
def cross(a, b):
    #x = x1 + k1t
    #y = y1 + k2t
    a1 = float(a[0]) #координата по x1 второго отрезка
    a2 = float(a[1])   #координата по y1 второго отрезка
    b1 = float(a[2]) - float(a[0])    #k1
    b2 = float(a[3]) - float(a[1])    #k2


    r1 = float(b[0])   #координата по x1 первого отрезка
    r2 = float(b[1])   #координата по y1 первого отрезка
    q1 = float(b[2]) - float(b[0])    #k1
    q2 = float(b[3]) - float(b[1])    #k2
    #прямые равны
    if (a ==b): return True
    #одна прямая параллельная оси
    if (b1 == 0 or q2 - b2 / b1 == 0 or b2 == 0): return False
    #направляющие векторы равны
    if (q1 / b1 == q2 / b2): return False
    #
    t2 = (a2 - r2 + b2 / b1 * (r1 - a1)) / (q2 - b2*q1/b1)
    t1 = (q1*t2 + r1 - a1) / b1
    if (round(t2, 5) >0 and round(t2, 5) < 1 and round(t1, 5)>0 and round(t1, 5)<1): return True
    return False

#пересекается ли хотя бы с одним ребром
def cross_all(a, b):
    cd = 0
    for i in range(len(mas_lines)):
        test = (a[0], a[1], b[0], b[1])
        if cross(test, mas_lines[i]) == True:
            cd += 1

    if (cd == 0) : return True
    return False

#рисование всех ребер
def draw_edges():
    global tochk
    global start
    global vertices
    for i in mas_lines:
        edges.append([(i[0], i[1], i[2], i[3]), ((i[0]-i[2])**2 + (i[1] - i[3])**2)**0.5])
    for i in range(len(mas_ver)-1):
        for j in range(i+1, len(mas_ver)):
            if (cross_all(mas_ver[i], mas_ver[j]) == True):
                if (mas_rect.count({mas_ver[i][0], mas_ver[i][1], mas_ver[j][0], mas_ver[j][1]}) == 0):
                    draw_line(mas_ver[i][0], mas_ver[i][1], mas_ver[j][0], mas_ver[j][1])
                    edges.append([[mas_ver[i][0], mas_ver[i][1], mas_ver[j][0], mas_ver[j][1]], ((mas_ver[j][0] - mas_ver[i][0])**2 + (mas_ver[j][1] - mas_ver[i][1])**2)**(0.5)])
                    vertices.add((mas_ver[i][0], mas_ver[i][1]))
                    vertices.add((mas_ver[j][0], mas_ver[j][1]))
    # print(type(Dijkstra(edges, vertices, start, end)))
    try:
        for i in tochk:
            draw_path(Dijkstra(edges, vertices, start, i))
            start = i
    except:
        showwarning(title="Предупреждение", message="Такой граф построить невозможно")
        clear_graph()

#вершина с min Dist
def get_min(Dist, sp):
    mi = 99999999999
    t = -1
    for i in sp:
        if Dist[i] < mi:
            mi = Dist[i]
            t = i
    return t

#рисование путя
def draw_path(tq):
    tq.append((start[0], start[1]))
    for i in range(len(tq)-1, 0, -1):
        canvas.create_line(tq[i][0], tq[i][1], tq[i-1][0], tq[i-1][1], fill="green", width=3)

#строение путя в обратном порядке
def BuildPath(Par, s, e):
    tq = []
    while(Par[(e[0], e[1])] != (s[0], s[1])):
        tq.append((e[0], e[1]))
        e = Par[(e[0], e[1])]
    tq.append((e[0], e[1]))
    return tq


#Алгоритм Дейкстры
def Dijkstra(graph, ver, st, en):
    Distance = {}
    for i in ver:
        # print(i)
        Distance[(i[0], i[1])] = 9999999999
    Distance[(st[0], st[1])] = 0
    Q = set()
    for i in ver:
        Q.add(i)
    temp = 0
    Parent = {}
    while (len(Q) != 0):
        temp = get_min(Distance, Q)
        Q.remove(temp)
        if (temp[0] == en[0] and temp[1] == en[1]):
            return BuildPath(Parent, st, en)
        s = get_all_edges(graph, temp)
        # print(s)
        for v in s:
            # try:
            if ((v[0][0], v[0][1]) in Distance.keys()):
                if Distance[(v[0][0], v[0][1])] > Distance[(temp[0], temp[1])] + v[1]:
                    Distance[(v[0][0], v[0][1])] = Distance[(temp[0], temp[1])] + v[1]
                    Parent[(v[0][0], v[0][1])] = temp
            # except:
            #     print("Exception")
    
#массив всех ребер смежных с точкой a
def get_all_edges(graph, a):
    t = []
    for i in graph:
        if (i[0][0] == a[0] and i[0][1] == a[1]):
            t.append([[i[0][2], i[0][3]], i[1]])
        elif (i[0][2] == a[0] and i[0][3] == a[1]):
            t.append([[i[0][0], i[0][1]], i[1]])
    return t




def draw_line(a, b, c, d):
    canvas.create_line(a, b, c, d, fill="red")

#создание прямоугольника
def click_button(event):
    canvas.create_oval(event.x-3,event.y-3, event.x+3, event.y+3, fill="red")
    mas.append((event.x, event.y))
    #добавление прямоугольника если отмечены 2 точки
    if (len(mas) >= 2):
        canvas.create_rectangle(mas[0][0],mas[0][1], mas[1][0],mas[1][1], fill="black")
        mas_rect.append({mas[0][0],mas[0][1], mas[1][0],mas[1][1]})
        line1 = (mas[0][0], mas[0][1], mas[0][0], mas[1][1]) #левая сторона
        line2 = (mas[0][0], mas[0][1], mas[1][0], mas[0][1]) #нижняя сторона
        line3 = (mas[1][0], mas[0][1], mas[1][0], mas[1][1]) #правая сторона
        line4 = (mas[0][0], mas[1][1], mas[1][0], mas[1][1]) #левый верхний угл
        rect.append([mas[0][0],mas[0][1], mas[1][0],mas[1][1]])
        draw_line(*line1)
        draw_line(*line2)
        draw_line(*line3)
        draw_line(*line4)
        mas_lines.append(line1)
        mas_lines.append(line2)
        mas_lines.append(line3)
        mas_lines.append(line4)
        canvas.create_oval(mas[0][0]-3,mas[0][1]-3, mas[0][0]+3, mas[0][1]+3, fill="red")
        canvas.create_oval(mas[1][0]-3,mas[0][1]-3, mas[1][0]+3,mas[0][1]+3, fill="red")
        canvas.create_oval(mas[1][0]-3,mas[1][1]-3, mas[1][0]+3, mas[1][1]+3, fill="red")
        canvas.create_oval(mas[0][0]-3,mas[1][1]-3, mas[0][0]+3, mas[1][1]+3, fill="red")
        mas_ver.append((mas[0][0], mas[0][1]))
        mas_ver.append((mas[1][0], mas[0][1]))
        mas_ver.append((mas[1][0], mas[1][1]))
        mas_ver.append((mas[0][0], mas[1][1]))
        mas.clear()


#точка старта точка конца
def add_conclusion_vertex(event):
    global tochk
    global end
    if len(start) > 0:
        canvas.create_oval(event.x-3,event.y-3, event.x+3, event.y+3, fill="yellow")
        end = []
        end.append(event.x)
        end.append(event.y)
        tochk.append(end)
        # draw_line(start[0], start[1], end[0], end[1])
    else:
        canvas.create_oval(event.x-3,event.y-3, event.x+3, event.y+3, fill="green")
        start.append(event.x)
        start.append(event.y)
    
    mas_ver.append((event.x,event.y))

#сохранение в json
def save():
    my_file = open(f"{m.get()}.json", "w+")
    t = []
    for i in rect:
        q = []
        for j in range(len(i)):
            q.append(i[j])
        t.append(q)
    json.dump({"react":t, "start": start, "end": end}, my_file)
    my_file.close()

#ввод через json
def file_open():
    f = open(f'{T.get()}.json', "r+")
    data = json.load(f)
    global start
    start = data["start"]
    canvas.create_oval(start[0]-3, start[1]-3, start[0]+3, start[1]+3, fill="yellow")
    global end
    end = data["end"]
    canvas.create_oval(end[0]-3, end[1]-3, end[0]+3, end[1]+3, fill="green")
    mas_ver.append((start[0], start[1]))
    mas_ver.append((end[0], end[1]))
    # global vertices
    vertices.add((start[0], start[1]))
    vertices.add((end[0], end[1]))
    for i in data["react"]:
        mas_rect.append({i[0], i[1], i[2], i[3]})
        rect.append([i[0], i[1], i[2], i[3]])
        canvas.create_rectangle(i, fill="black")
        line1 = (i[0], i[1], i[0], i[3]) #левая сторона
        line2 = (i[0], i[1], i[2], i[1]) #нижняя сторона
        line3 = (i[0], i[3], i[2], i[3]) #верхняя сторона
        line4 = (i[2], i[3], i[2], i[1]) #правая сторона
        draw_line(*line1)
        draw_line(*line2)
        draw_line(*line3)
        draw_line(*line4)
        canvas.create_oval(i[0]-3,i[1]-3, i[0]+3, i[1]+3, fill="red")
        canvas.create_oval(i[0]-3,i[3]-3, i[0]+3, i[3]+3, fill="red")
        canvas.create_oval(i[2]-3,i[3]-3, i[2]+3, i[3]+3, fill="red")
        canvas.create_oval(i[2]-3,i[1]-3, i[2]+3, i[1]+3, fill="red")
        mas_lines.append(line1)
        mas_lines.append(line2)
        mas_lines.append(line3)
        mas_lines.append(line4)
        mas_ver.append((i[0], i[1]))
        mas_ver.append((i[0], i[3]))
        mas_ver.append((i[2], i[1]))
        mas_ver.append((i[2], i[3]))

def clear_graph():
    canvas.create_rectangle(0, 0, 600, 800, fill="white", outline='white')
    global mas
    mas = []
    global mas_rect
    mas_rect = []       #массив всех
    global mas_ver
    mas_ver = []        #массив всех вершин и пряпятствий и точек 
    global mas_lines
    mas_lines = []      #массив всех граней препятствий 
    global rect
    rect = []
    global start
    start = []          #точка начала
    global end
    end = []            #точка конца
    global edges
    edges = []          #множество ребер
    global vertices
    vertices = set()    #множество вершин




canvas = Canvas(bg="white", width=600, height=800)
canvas.pack(anchor="nw", expand=1)
btn = ttk.Button(text="Draw graph", command=draw_edges)
btn.place(x=620, y=70, width=120, height=20)    # размещаем кнопку в окне

T = ttk.Entry()
T.place(x=620, y=100, width=120, height=20)

op_file = ttk.Button(text="Open json", command=file_open)
op_file.place(x=620, y=130, width=120, height=20)

m = ttk.Entry()
m.place(x=620, y=160, width=120, height=20)
op_file = ttk.Button(text="Save", command=save)
op_file.place(x=620, y=190, width=  120, height=20)

clear_all = ttk.Button(text="Clear_all", command=clear_graph)
clear_all.place(x=620, y=220, width=  120, height=20)

canvas.bind('<Button-3>', add_conclusion_vertex)
canvas.bind('<Button-1>', click_button)

# print(cross([2, 2, 7, 3],[4, 1, 5, 6]))
# print(cross([5, 4, 10, 5],[3, 3, 7, 6]))
# print(cross([0, 0, 5, 5],[3, 3, 7, 7]))
root.mainloop()