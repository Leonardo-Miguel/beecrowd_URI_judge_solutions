#include <bits/stdc++.h>
using namespace std;

/*
The general idea of ??the proposed solution is to create a complete graph, that is,
in which there are edges connecting each vertex to all the others, and based on the distance
between each pair of vertices, use Prim's algorithm to find the minimum spanning tree (MST).
This way, all people would be connected using the smallest amount of web possible.
*/
	
const int MAX_N = 10000;

class Vertex {
public:
    int id;
    int coord_x;
    int coord_y;
    double adj[MAX_N];
    double distance;
    bool finished;

    Vertex(int id, int coord_x, int coord_y) {
        this->id = id;
        this->coord_x = coord_x;
        this->coord_y = coord_y;
        this->distance = numeric_limits<double>::infinity();
        this->finished = false;
    }
};

vector<Vertex*> build_graph(vector<string>& all_rows, int position, int n) {
    vector<Vertex*> group_graph;

    for (int i = position + 2; i < position + 2 + n; ++i) {
        istringstream iss(all_rows[i]);
        int coord_x, coord_y;
        iss >> coord_x >> coord_y;
        Vertex* vertex = new Vertex(i, coord_x, coord_y);
        group_graph.push_back(vertex);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            Vertex* u = group_graph[i];
            Vertex* v = group_graph[j];
            double distance_uv = sqrt(pow(v->coord_x - u->coord_x, 2) + pow(v->coord_y - u->coord_y, 2));
            u->adj[j] = distance_uv;
            v->adj[i] = distance_uv;
        }
    }

    return group_graph;
}

class CompareDistances {
public:
    bool operator()(pair<double, Vertex*>& p1, pair<double, Vertex*>& p2) {
        return p1.first > p2.first;
    }
};

double prim(vector<Vertex*>& graph, int n) {
    double mst_length = 0;
    priority_queue<pair<double, Vertex*>, vector<pair<double, Vertex*> >, CompareDistances> min_heap;
    graph[0]->distance = 0;
    min_heap.push(make_pair(0, graph[0]));

    while (!min_heap.empty()) {
        double current_distance = min_heap.top().first;
        Vertex* u = min_heap.top().second;
        min_heap.pop();

        if (u->finished) {
            continue;
        }
        u->finished = true;
        mst_length += current_distance;

        for (int v_id = 0; v_id < n; ++v_id) {
            if (!graph[v_id]->finished && graph[v_id]->distance > u->adj[v_id]) {
                graph[v_id]->distance = u->adj[v_id];
                min_heap.push(make_pair(u->adj[v_id], graph[v_id]));
            }
        }
    }

    return mst_length;
}

int main() {
    vector<string> all_rows;
    string line;

    while (getline(cin, line)) {
        all_rows.push_back(line);
    }
    
    /*
    ifstream file("4_queda_livre.txt");
    while (getline(file, line)) {
        all_rows.push_back(line);
    }
    file.close();
	*/
	
    vector<double> solutions;

    int c;
    stringstream(all_rows[0]) >> c;
    int verify_c = 0;
    int position = 0;

    while (verify_c < c) {
        int n;
        stringstream(all_rows[position + 1]) >> n;
        vector<Vertex*> graph = build_graph(all_rows, position, n);
        double mst_length = prim(graph, n) / 100;
        mst_length = round(mst_length * 100) / 100.0;
        solutions.push_back(mst_length);

        for (int i = 0; i < n; ++i) {
            delete graph[i];
        }

        position = position + n + 1;
        verify_c++;
    }

    for (size_t i = 0; i < solutions.size(); ++i) {
        cout << fixed << setprecision(2) << solutions[i] << endl;
    }

    return 0;
}

