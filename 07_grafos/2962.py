import sys
import math

'''
The general idea of ​​the presented solution is to create a graph in which the
'connected' sensors, that is, those in which their range radii overlap,
form the connected components. When building the graph, the distances to each
of the walls are evaluated, and the walls that the vertex 'touches' are stored as attributes.
When traversing the connected components of the graph, the walls of each component vertex
are checked, as these will make up the walls of the component itself.
Therefore, if at least one component has one of the pairs of walls that block the thief
(up and down, left and right, up and right, down and left), then the solution is that it is
not possible to reach the art. Otherwise, the path allows this range.
'''

class Vertex:
    def __init__(self, id, coord_x, coord_y, sensibility):
        self.id = id
        self.coord_x = coord_x
        self.coord_y = coord_y
        self.sensibility = sensibility
        self.visited = 0
        self.adj = []
        self.walls = []


def build_graph(all_rows, m, n, k):
        
    graph_vertices = []
    for i in range(1, k + 1):
        info_sensor = all_rows[i].split()
        x, y, s = int(info_sensor[0]), int(info_sensor[1]), int(info_sensor[2])
        vertex = Vertex(i, x, y, s)
        graph_vertices.append(vertex)
        
        # storing the walls that the vertex reachs
        if x + s >= m:
            vertex.walls.append('right')
        if x - s <= 0:
            vertex.walls.append('left')
        if y - s <= 0:
            vertex.walls.append('bottom')
        if y + s >= n:
            vertex.walls.append('top')

    for i in range(len(graph_vertices)):
        u = graph_vertices[i]
        for j in range(i + 1, len(graph_vertices)):
            v = graph_vertices[j]
            distance_uv = math.sqrt((v.coord_x - u.coord_x)**2 + (v.coord_y - u.coord_y)**2)

            # creating edges between the vertices in which their range radii overlap
            if distance_uv <= u.sensibility + v.sensibility:
                u.adj.append(v)
                v.adj.append(u)
                
    return graph_vertices

def BFS(graph):
    
    solution = 'S'
    
    for w in graph:
        if w.visited == 0:
            walls_component = []
            queue = [w]
            w.visited = 1
            while len(queue) != 0:
                v = queue.pop(0)
                for wall in v.walls:
                    if wall not in walls_component:
                        walls_component.append(wall)
                                
                for u in v.adj:
                    if u.visited == 0:
                        queue.append(u)
                        u.visited = 1

            # verifying the walls of the connected component in the graph
            if 'bottom' in walls_component and 'top' in walls_component:
                solution = 'N'
            elif 'bottom' in walls_component and 'left' in walls_component:
                solution = 'N'
            elif 'top' in walls_component and 'right' in walls_component:
                solution = 'N'
            elif 'left' in walls_component and 'right' in walls_component:
                solution = 'N'


        if solution == 'N':
            break
    
    return solution
    
#####################
 
#with open('6_arte_valiosa.txt', 'r') as file:
#    all_rows = file.readlines() 
    
all_rows = sys.stdin.readlines()

info_input = all_rows[0].split()
m, n, k = float(info_input[0]), float(info_input[1]), int(info_input[2])

graph = build_graph(all_rows, m, n, k)

answer = BFS(graph)

print(answer)
