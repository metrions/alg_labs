for i in tochk:
        vertices.add((i[0], i[1]))
        draw_path(Dijkstra(edges, vertices, start, i))
        start = i