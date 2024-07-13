import sys

'''
The general proposal of the solution presented is to find the path with
fewer soldiers, connecting the departure to the destination.
For this purpose, the Dijkstra algorithm is used. If there are enough bullets,
that is, more bullets than soldiers on the way, the probability provided is used to verify
the probability of being able to hit all the soldiers on the path found.
'''

class Vertex:
    def __init__(self, id):
        self.id = id
        self.adj = []
        self.shooters = 0
        self.finished = 0
        self.path_shooters = float('inf')
        self.father = None

def build_graph(n, m, shooters, all_rows, start_instance_row):
    graph = {}
    for i in range(1, n + 1):
        vertex = Vertex(i)
        graph[i] = vertex

    for road in range(start_instance_row + 1, start_instance_row + m + 1):
        initial_v_id, terminal_v_id = all_rows[road].split()
        initial_v_id, terminal_v_id = int(initial_v_id), int(terminal_v_id)
        
        initial_vertex = graph[initial_v_id]
        terminal_vertex = graph[terminal_v_id]
        
        initial_vertex.adj.append(terminal_vertex)
        terminal_vertex.adj.append(initial_vertex)

    for i in range(1, len(shooters)):
        vertex = int(shooters[i])
        graph[vertex].shooters += 1

    return graph

def dijkstra(graph, source, destiny, k, p):
    source_vertex = graph[source]
    source_vertex.path_shooters = source_vertex.shooters
    destiny_vertex = graph[destiny]
    
    set_q = list(graph.values())
    
    while set_q:
        set_q.sort(key=lambda vert: vert.path_shooters)
        nearest_vertex = set_q.pop(0)
        nearest_vertex.finished = 1

        for neighbor in nearest_vertex.adj:
            if neighbor.finished == 0:
                new_shooters_count = nearest_vertex.path_shooters + neighbor.shooters
                if neighbor.path_shooters > new_shooters_count:
                    neighbor.path_shooters = new_shooters_count
                    neighbor.father = nearest_vertex

    total_path_shooters = destiny_vertex.path_shooters
    
    if total_path_shooters == float('inf'):
        return 0
    
    if k >= total_path_shooters:
        answer = p ** total_path_shooters
    else:
        answer = 0
        
    return answer

#####################
 
#with open('2_leningrado.txt', 'r') as file:
#    all_rows = file.readlines() 
    
all_rows = sys.stdin.readlines()

solutions = []

start_instance_row = 0

while start_instance_row < len(all_rows):
    instance_row = all_rows[start_instance_row].split()
    
    n, m, k, p = int(instance_row[0]), int(instance_row[1]), int(instance_row[2]), float(instance_row[3])

    shooters_row = start_instance_row + m + 1
    shooters = all_rows[shooters_row].split()
    a = int(shooters[0])

    graph = build_graph(n, m, shooters, all_rows, start_instance_row)
    
    source_destiny_row = start_instance_row + m + 2
    source_destiny = all_rows[source_destiny_row].split()
    source, destiny = int(source_destiny[0]), int(source_destiny[1])

    prob_max = round(dijkstra(graph, source, destiny, k, p), 3)
    solutions.append(prob_max)

    start_instance_row = start_instance_row + m + 3
  
for solution in solutions:
    print('{:.3f}'.format(solution))
