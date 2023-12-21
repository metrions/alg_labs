from tkinter import *
from tkinter import ttk
from tkinter.messagebox import showerror, showwarning, showinfo
import json

root = Tk()  # создаем корневой объект - окно
root.title("Приложение на Tkinter")  # устанавливаем заголовок окна
root.geometry("800x800")  # устанавливаем размеры окна

mas = []  # массив для рисования прямоугольников
mas_rect = []  # массив всех
mas_ver = []  # массив всех вершин и пряпятствий и точек
mas_lines = []  # массив всех граней препятствий
rect = []
tochk = []  # массив промежуточных точек
mas_lines_rect = []  # массив линий прямоугольников

start = []  # точка начала
end = []  # точка конца
edges = []  # множество ребер
vertices = set()  # множество вершин


# пересекаются ли отрезки
def cross(a, b):
    # x = x1 + k1t
    # y = y1 + k2t
    a1 = float(a[0])  # координата по x1 второго отрезка
    a2 = float(a[1])  # координата по y1 второго отрезка
    b1 = float(a[2]) - float(a[0])  # k1
    b2 = float(a[3]) - float(a[1])  # k2

    r1 = float(b[0])  # координата по x1 первого отрезка
    r2 = float(b[1])  # координата по y1 первого отрезка
    q1 = float(b[2]) - float(b[0])  # k1
    q2 = float(b[3]) - float(b[1])  # k2
    # прямые равны
    # одна прямая параллельная оси
    if (a == b): return False
    if (b1 == 0 or q2 - b2 / b1 == 0 or b2 == 0 or q1 / b1 == q2 / b2):
        cx = sorted([a[0], a[2]])
        dx = sorted([b[0], b[2]])
        cy = sorted([a[1], a[3]])
        dy = sorted([b[1], b[3]])
        if (cx[0] > dx[0] and cx[0] < dx[1]):
            return True
        # elif (cx[1] > dx[0] and cx[1] < dx[1]): return True
        elif (cy[0] > dy[0] and cy[0] < dy[1]):
            return True
        return False
    # направляющие векторы равны
    if (q1 / b1 == q2 / b2): return False
    #
    t2 = (a2 - r2 + b2 / b1 * (r1 - a1)) / (q2 - b2 * q1 / b1)
    t1 = (q1 * t2 + r1 - a1) / b1
    if (t2 > 0 and t2 < 1 and t1 > 0 and t1 < 1): return True
    return False


# пересекается ли хотя бы с одним ребром
def cross_all(a, b):
    cd = 0
    for i in range(len(mas_lines)):
        test = (a[0], a[1], b[0], b[1])
        if cross(test, mas_lines[i]) == True:
            cd += 1
    if (cd == 0): return True
    return False


# рисование всех ребер
def draw_edges():
    global tochk
    global start
    global vertices
    # так как в формуле коэфициенты могут быть равны 0, а на 0 делить нельзя массив отрезков с 0 коэф рассматривается отдельно
    for i in mas_lines_rect:
        d = False
        for j in mas_lines_rect:
            if (i != j):
                cx = sorted([i[0], i[2]])
                dx = sorted([j[0], j[2]])
                cy = sorted([i[1], i[3]])
                dy = sorted([j[1], j[3]])

                if (cx[1] > dx[0] and cx[1] < dx[1]):
                    if (cy[0] > dy[0] and cy[0] < dy[1]):
                        d = True
                    if (dy[0] > cy[0] and dy[0] < cy[1]):
                        d = True
                if (dx[1] > cx[0] and dx[1] < cx[1]):
                    if (cy[0] > dy[0] and cy[0] < dy[1]):
                        d = True
                    if (dy[0] > cy[0] and dy[0] < cy[1]):
                        d = True
        if (d == False):
            draw_line(i[0], i[1], i[2], i[3])
            edges.append([(i[0], i[1], i[2], i[3]), ((i[0] - i[2]) ** 2 + (i[1] - i[3]) ** 2) ** 0.5])

    # добавление отрезков из точек
    for i in range(len(mas_ver) - 1):
        for j in range(i + 1, len(mas_ver)):
            if (cross_all(mas_ver[i], mas_ver[j]) == True):
                if (mas_rect.count({mas_ver[i][0], mas_ver[i][1], mas_ver[j][0], mas_ver[j][1]}) == 0):
                    draw_line(mas_ver[i][0], mas_ver[i][1], mas_ver[j][0], mas_ver[j][1])
                    edges.append([[mas_ver[i][0], mas_ver[i][1], mas_ver[j][0], mas_ver[j][1]],
                                  ((mas_ver[j][0] - mas_ver[i][0]) ** 2 + (mas_ver[j][1] - mas_ver[i][1]) ** 2) ** (
                                      0.5)])
                    vertices.add((mas_ver[i][0], mas_ver[i][1]))
                    vertices.add((mas_ver[j][0], mas_ver[j][1]))
    # построение пути
    if (len(start) == 0 or len(tochk) == 0):
        showwarning(title="Предупреждение", message="Некорректный ввод данных")
        clear_graph()
    try:
        q = [start[0], start[1]]
        for i in tochk:
            draw_path(Dijkstra(edges, vertices, start, i))
            start = i
        start = [q[0], q[1]]
    except:
        showwarning(title="Предупреждение", message="Нет пути")
        clear_graph()


# вершина с min Dist
def get_min(Dist, sp):
    mi = 99999999999
    t = -1
    for i in sp:
        if Dist[i] < mi:
            mi = Dist[i]
            t = i
    return t


# рисование путя
def draw_path(tq):
    tq.append((start[0], start[1]))
    for i in range(len(tq) - 1, 0, -1):
        canvas.create_line(tq[i][0], tq[i][1], tq[i - 1][0], tq[i - 1][1], fill="green", width=3)
    # for i in mas_rect:
    #     canvas.create_rectangle(i[0], i[1], i[2], i[3])


# строение путя в обратном порядке
def BuildPath(Par, s, e):
    tq = []
    while (Par[(e[0], e[1])] != (s[0], s[1])):
        tq.append((e[0], e[1]))
        e = Par[(e[0], e[1])]
    tq.append((e[0], e[1]))
    return tq


# Алгоритм Дейкстры
def Dijkstra(graph, ver, st, en):
    Distance = {}
    for i in ver:
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
        for v in s:
            if ((v[0][0], v[0][1]) in Distance.keys()):
                if Distance[(v[0][0], v[0][1])] > Distance[(temp[0], temp[1])] + v[1]:
                    Distance[(v[0][0], v[0][1])] = Distance[(temp[0], temp[1])] + v[1]
                    Parent[(v[0][0], v[0][1])] = temp


# массив всех ребер смежных с точкой a
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


# создание прямоугольника
def click_button(event):
    canvas.create_oval(event.x - 3, event.y - 3, event.x + 3, event.y + 3, fill="red")
    mas.append((event.x, event.y))

    # добавление треугольника, если отмечены 3 точки
    if len(mas) >= 3:
        canvas.create_polygon(mas[0][0], mas[0][1], mas[1][0], mas[1][1], mas[2][0], mas[2][1], fill="black")

        # Добавляем вершины треугольника в массив mas_ver
        for point in mas:
            mas_ver.append((point[0], point[1]))

        # Создаем ребра треугольника
        line1 = (mas[0][0], mas[0][1], mas[1][0], mas[1][1])
        line2 = (mas[1][0], mas[1][1], mas[2][0], mas[2][1])
        line3 = (mas[2][0], mas[2][1], mas[0][0], mas[0][1])

        # Добавляем ребра треугольника в массив mas_lines
        mas_lines.extend([line1, line2, line3])

        # Рисуем ребра треугольника
        draw_line(*line1)
        draw_line(*line2)
        draw_line(*line3)

        # Очищаем массив mas после добавления треугольника
        mas.clear()


# точка старта точка конца
def add_conclusion_vertex(event):
    global tochk
    global start
    global end
    if len(start) > 0:
        canvas.create_oval(event.x - 3, event.y - 3, event.x + 3, event.y + 3, fill="yellow")
        end = []
        end.append(event.x)
        end.append(event.y)
        tochk.append(end)
        # draw_line(start[0], start[1], end[0], end[1])
    else:
        canvas.create_oval(event.x - 3, event.y - 3, event.x + 3, event.y + 3, fill="green")
        start.append(event.x)
        start.append(event.y)

    mas_ver.append((event.x, event.y))


def save():
    my_file = open(f"{m.get()}.json", "w+")

    t_rect = []  # массив для хранения координат треугольников
    for i in mas_ver:
        t_rect.append(i)

    t_lines_rect = []  # массив для хранения ребер треугольников
    for i in mas_lines:
        t_lines_rect.append([i[0], i[1], i[2], i[3]])

    t_tochk = []  # массив для хранения координат точек
    for i in tochk:
        t_tochk.append(i)

    json.dump({"ver": t_rect, "lines": t_lines_rect, "start": start, "end": end, "tochk": t_tochk}, my_file)
    my_file.close()


def file_open():
    f = open(f'{T.get()}.json', "r+")
    data = json.load(f)
    global start
    global tochk
    global end
    global mas_lines_rect
    global mas_lines
    tochk = data["tochk"]
    start = data["start"]
    canvas.create_oval(start[0] - 3, start[1] - 3, start[0] + 3, start[1] + 3, fill="yellow")

    for i in tochk:
        end = i
        canvas.create_oval(end[0] - 3, end[1] - 3, end[0] + 3, end[1] + 3, fill="green")
        mas_ver.append((i[0], i[1]))
        vertices.add((i[0], i[1]))

    mas_ver.append((start[0], start[1]))
    vertices.add((start[0], start[1]))

    t_rect = data["ver"]  # массив для хранения координат треугольников
    for i in t_rect:
        mas_ver.append(i)

    t_lines_rect = data["lines"]  # массив для хранения ребер треугольников
    for i in t_lines_rect:
        mas_lines.append((i[0], i[1], i[2], i[3]))
        draw_line(i[0], i[1], i[2], i[3])

    canvas.create_polygon(mas_lines[0][0], mas_lines[0][1], mas_lines[1][0], mas_lines[1][1], mas_lines[2][0],
                          mas_lines[2][1], fill="black")

    f.close()


def clear_graph():
    canvas.create_rectangle(0, 0, 600, 800, fill="white", outline='white')
    global mas
    mas = []
    global mas_rect
    mas_rect = []  # массив всех
    global mas_ver
    mas_ver = []  # массив всех вершин и пряпятствий и точек
    global mas_lines
    mas_lines = []  # массив всех граней препятствий
    global rect
    rect = []
    global start
    start = []  # точка начала
    global end
    end = []  # точка конца
    global edges
    edges = []  # множество ребер
    global vertices
    vertices = set()  # множество вершин
    global tochk
    tochk = []
    global mas_lines_rect
    mas_lines_rect = []


canvas = Canvas(bg="white", width=600, height=800)
canvas.pack(anchor="nw", expand=1)
btn = ttk.Button(text="Draw graph", command=draw_edges)
btn.place(x=620, y=70, width=120, height=20)  # размещаем кнопку в окне

T = ttk.Entry()
T.place(x=620, y=100, width=120, height=20)

op_file = ttk.Button(text="Open json", command=file_open)
op_file.place(x=620, y=130, width=120, height=20)

m = ttk.Entry()
m.place(x=620, y=160, width=120, height=20)
op_file = ttk.Button(text="Save", command=save)
op_file.place(x=620, y=190, width=120, height=20)

clear_all = ttk.Button(text="Clear_all", command=clear_graph)
clear_all.place(x=620, y=220, width=120, height=20)

canvas.bind('<Button-3>', add_conclusion_vertex)
canvas.bind('<Button-1>', click_button)

root.mainloop()