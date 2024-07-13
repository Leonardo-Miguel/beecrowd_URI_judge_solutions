import sys

'''
The proposed solution consists of creating a (directed) graph in which the connected
components are identified through pairs of letters that translate one to the other.
In this way, a breadth-first search (BFS) is used to traverse the paths from a letter
to the one that translates it. Thus, when scanning each letter of a word, a match is
looked for in the word to be translated, so that if all letters have a translation,
then the translation is valid.
'''

class Vertex:
    def __init__(self, name):
        self.name = name
        self.visited = 0
        self.adj = []


def build_graph(all_rows, m):
        
    graph_vertices = {}

    for i in range(1, m + 1):

        row = all_rows[i].split()
        vertex_name = row[0]
        adjacence = row[1]
        
        if vertex_name not in graph_vertices:
            graph_vertices[vertex_name] = Vertex(vertex_name)

        if adjacence not in graph_vertices:
            graph_vertices[adjacence] = Vertex(adjacence)

    for i in range(1, m + 1):
        row = all_rows[i].split()
        vertex_name = row[0]
        adjacence = row[1]
        
        graph_vertices[vertex_name].adj.append(graph_vertices[adjacence])
    

    return graph_vertices

def BFS(graph, charactere1, charactere2):
    
    equivalence_counter = 0
    
    for vertex in graph.values():
        vertex.visited = 0  # Resetting the visited status for current BFS application
        
    queue = []
    queue.append(graph[charactere1])
    graph[charactere1].visited = 1
    
    while len(queue) != 0:
        v = queue.pop()
        if v.name == charactere2:
            equivalence_counter = equivalence_counter + 1
            break
        for u in v.adj:
            if u.visited == 0:
                queue.append(u)
                u.visited = 1
        v.visited = 2
        
    return equivalence_counter
    
    
#####################
 
#with open('5_secret_chamber.txt', 'r') as file:
#    all_rows = file.readlines() 
    
all_rows = sys.stdin.readlines()

n_letters_words = all_rows[0].split()
m, n = int(n_letters_words[0]), int(n_letters_words[1])

graph = build_graph(all_rows, m)

all_answers = []    
for i in range(m + 1, m + n + 1):
    row = all_rows[i].split()
    word1 = row[0]
    word2 = row[1]
    
    answer = 'no'
    if word1 == word2:
        answer = 'yes'

    elif len(word1) == len(word2):
        answer_counter = 0
        for index in range(len(word1)): # traverse each letter at the both words
            charactere1 = word1[index]
            charactere2 = word2[index]

            if charactere1 == charactere2:
                answer_counter = answer_counter + 1
            elif charactere1 in graph:
                answer_counter = answer_counter + BFS(graph, charactere1, charactere2)
            else:
                answer = 'no'
                break
        
        if answer_counter == len(word1): # means that all letters in thw word was traduced
            answer = 'yes'
            
    all_answers.append(answer)    
            
for solution in all_answers:
    print(solution)
