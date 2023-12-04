import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle, Circle, Polygon

def draw_shape(ax, shape, size, position):
    if shape == "треугольник":
        points = [[position[0], position[1]], [position[0] + size, position[1]], [position[0] + size / 2, position[1] + size]]
        shape_plot = Polygon(points, closed=True, edgecolor='black', facecolor='black')
    elif shape == "прямоугольник":
        shape_plot = Rectangle(position, size[0], size[1], edgecolor='black', facecolor='black')
    elif shape == "круг":
        shape_plot = Circle(position, size, edgecolor='black', facecolor='black')

    ax.add_patch(shape_plot)

shapes = []
sizes = []
positions = []

n = int(input("Введите количество фигур: "))

for i in range(n):
    shape = input("Выберите фигуру (треугольник, прямоугольник, круг) для фигуры {}: ".format(i+1))
    size = float(input("Выберите размер фигуры {}: ".format(i+1)))
    x = float(input("Введите координату X для фигуры {}: ".format(i+1)))
    y = float(input("Введите координату Y для фигуры {}: ".format(i+1)))
    position = (x, y)

    shapes.append(shape)
    sizes.append(size)
    positions.append(position)

fig, ax = plt.subplots()

for shape, size, position in zip(shapes, sizes, positions):
    draw_shape(ax, shape, size, position)

plt.axis('equal')
plt.show()