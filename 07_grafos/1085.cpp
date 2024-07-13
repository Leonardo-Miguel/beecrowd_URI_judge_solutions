#include <bits/stdc++.h>
using namespace std;

/*
The general proposal of this solution is to build a graph with the words at its vertices.
Words with common languages are connected by edges, except those with the same initial letters.
The Dijkstra algorithm is used to calculate the shortest path connecting source words with the nearest target word.
Since multiple words can be sourced, the algorithm is run for each source and, in the end,
the shortest path connecting a source to a destination is chosen.
*/

const double INF = numeric_limits<double>::max();

class Vertex {
public:
    string I1, I2, P;
    int length;
    vector<Vertex*> adj;
    double distance;
    bool finished;

    Vertex(string i1, string i2, string p) : I1(i1), I2(i2), P(p), length(p.length()), distance(INF), finished(false) {}
};

struct ComparePair {
    bool operator()(const pair<double, Vertex*>& lhs, const pair<double, Vertex*>& rhs) {
        return lhs.first > rhs.first;
    }
};


vector<Vertex*> build_graph(const vector<string>& all_rows, int row_index, int M) {
    vector<Vertex*> graph_vertices;

    for (int i = row_index + 2; i < row_index + M + 2; ++i) {
        istringstream iss(all_rows[i]);
        string I1, I2, P;
        iss >> I1 >> I2 >> P;
        Vertex* vertex = new Vertex(I1, I2, P);
        graph_vertices.push_back(vertex);
    }

	// adding edges between vertices/words with common languages, except those with the same initial letter
    for (size_t i = 0; i < graph_vertices.size(); ++i) {
        for (size_t j = 0; j < graph_vertices.size(); ++j) {
            if (i != j) {
                Vertex* v = graph_vertices[i];
                Vertex* u = graph_vertices[j];
                bool cond1 = (v->I1 == u->I1 || v->I1 == u->I2 || v->I2 == u->I1 || v->I2 == u->I2);
                if (cond1 && v->P[0] != u->P[0]) {
                    v->adj.push_back(u);
                }
            }
        }
    }

    return graph_vertices;
}

// identifying the vertices with the initial and final languages, to mark the sources and destinations for executing the shortest path algorithm (Dijkstra)
void find_sources_and_destinations(const vector<Vertex*>& graph_vertices, const string& O, const string& D, vector<Vertex*>& sources, vector<Vertex*>& destinations) {
    for (size_t i = 0; i < graph_vertices.size(); ++i) {
        Vertex* v = graph_vertices[i];
        if (v->I1 == O || v->I2 == O) {
            sources.push_back(v);
        }
        if (v->I1 == D || v->I2 == D) {
            destinations.push_back(v);
        }
    }
}

double dijkstra(vector<Vertex*>& graph_vertices, Vertex* source, const vector<Vertex*>& destinations) {
    set<Vertex*> set_s;
    priority_queue<pair<double, Vertex*>, vector<pair<double, Vertex*> >, ComparePair> priority_queue;
    source->distance = source->length;
    priority_queue.push(make_pair(source->distance, source));

    while (!priority_queue.empty()) {
        double current_distance = priority_queue.top().first;
        Vertex* nearest_vertex = priority_queue.top().second;
        priority_queue.pop();

        if (nearest_vertex->finished) {
            continue;
        }
        nearest_vertex->finished = true;

        if (find(destinations.begin(), destinations.end(), nearest_vertex) != destinations.end()) {
            return nearest_vertex->distance;
        }

        set_s.insert(nearest_vertex);

		// the comparison "distance" is the length of the word, symbolizing the weight of the edge. This way, pairs of words with shorter lengths will be chosen by the Dijkstra algorithm when looking for the shortest path to a destination vertex.
        for (size_t i = 0; i < nearest_vertex->adj.size(); ++i) {
            Vertex* neighbor = nearest_vertex->adj[i];
            if (!neighbor->finished) {
                double new_distance = nearest_vertex->distance + neighbor->length;
                if (new_distance < neighbor->distance) {
                    neighbor->distance = new_distance;
                    priority_queue.push(make_pair(neighbor->distance, neighbor));
                }
            }
        }
    }

    return INF;
}

int main() {
    
    vector<string> all_rows;
    string line;

	while (getline(cin, line)) {
        all_rows.push_back(line);
    }
    
	/*
	ifstream file("1_babel_inputs.txt");
    while (getline(file, line)) {
        all_rows.push_back(line);
    }
    file.close();
	*/
	
    vector<string> all_solutions;
    int row_index = 0;

    while (row_index < all_rows.size()) {
        istringstream iss(all_rows[row_index]);
        int M;
        iss >> M;

        if (M >= 1 && M <= 2000) {
            istringstream iss2(all_rows[row_index + 1]);
            string O, D;
            iss2 >> O >> D;

            vector<Vertex*> graph_vertices = build_graph(all_rows, row_index, M);
            vector<Vertex*> sources, destinations;
            find_sources_and_destinations(graph_vertices, O, D, sources, destinations);

            if (!sources.empty() && !destinations.empty()) {
                double min_path_length = INF;

				# using Dijkstra for each possible source vertex
                for (size_t i = 0; i < sources.size(); ++i) {
                    for (size_t j = 0; j < graph_vertices.size(); ++j) {
                        graph_vertices[j]->distance = INF;
                        graph_vertices[j]->finished = false;
                    }

                    double path_length = dijkstra(graph_vertices, sources[i], destinations);
                    min_path_length = min(min_path_length, path_length);
                }

                if (min_path_length == INF) {
                    all_solutions.push_back("impossivel");
                } else {
                    ostringstream oss;
                    oss << min_path_length;
                    all_solutions.push_back(oss.str());
                }
            } else {
                all_solutions.push_back("impossivel");
            }
        }
        row_index += M + 2;
    }

    for (size_t i = 0; i < all_solutions.size(); ++i) {
        cout << all_solutions[i] << endl;
    }

    return 0;
}

