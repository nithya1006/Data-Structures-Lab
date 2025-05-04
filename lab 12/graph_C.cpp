//To implement Graph ADT with the implementation for Prim’s algorithm, Kruskal’s algorithm, and Dijkstra’s algorithm
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adjList;

    struct Edge {
        int u, v, weight;
        bool operator<(const Edge& other) const {
            return weight < other.weight;
        }
    };

    // Helper function for Prim's Algorithm
    int minKey(vector<int>& key, vector<bool>& inMST) {
        int minVal = INF, minIndex = -1;
        for (int v = 0; v < V; ++v) {
            if (!inMST[v] && key[v] < minVal) {
                minVal = key[v];
                minIndex = v;
            }
        }
        return minIndex;
    }

    vector<int> parent, rank;

    void makeSet() {
        parent.resize(V);
        rank.resize(V, 0);
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
    }

    int findSet(int u) {
        if (u != parent[u])
            parent[u] = findSet(parent[u]);
        return parent[u];
    }

    void unionSets(int u, int v) {
        u = findSet(u);
        v = findSet(v);
        if (u != v) {
            if (rank[u] < rank[v])
                parent[u] = v;
            else if (rank[u] > rank[v])
                parent[v] = u;
            else {
                parent[v] = u;
                rank[u]++;
            }
        }
    }

public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int, int, int);
    void display();
    void primMST();
    void kruskalMST();
    void dijkstra(int);
};

int main() {
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    if (vertices <= 0) {
        cout << "Number of vertices must be positive!\n";
        return 1;
    }

    Graph g(vertices);

    int choice;
    do {
        cout << "\n--- Graph Menu ---\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. Prim's MST\n";
        cout << "4. Kruskal's MST\n";
        cout << "5. Dijkstra's Shortest Paths\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int u, v, w;
            cout << "Enter vertices u and v and weight w: ";
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
            break;
        }
        case 2:
            g.display();
            break;
        case 3:
            g.primMST();
            break;
        case 4:
            g.kruskalMST();
            break;
        case 5: {
            int src;
            cout << "Enter source vertex: ";
            cin >> src;
            g.dijkstra(src);
            break;
        }
        case 6:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

//Function to insert an edge between a source vertex and destination vertex and weight
void Graph::addEdge(int u, int v, int w) {
    if (u >= V || v >= V || u < 0 || v < 0) {
        cout << "Invalid vertices for edge!\n";
        return;
    }
    adjList[u].push_back({v, w});
    adjList[v].push_back({u, w}); // undirected graph
}

//Function to display the graph adjacency list
void Graph::display() {
    cout << "\nGraph adjacency list:\n";
    for (int i = 0; i < V; i++) {
        cout << i << " -> ";
        for (auto& neighbor : adjList[i]) {
            cout << "(" << neighbor.first << ", weight=" << neighbor.second << ") ";
        }
        cout << endl;
    }
}

//Function to implement Prim's algorithm
void Graph::primMST() {
    vector<int> key(V, INF);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);

    for (int start = 0; start < V; ++start) {
        if (inMST[start]) continue; // already included in MST

        key[start] = 0;

        for (int count = 0; count < V; ++count) {
            int u = minKey(key, inMST);
            if (u == -1) break; // no available vertex

            inMST[u] = true;

            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                }
            }
        }
    }

    cout << "\nPrim's MST (or Forest if disconnected):\n";
    for (int i = 0; i < V; i++) {
        if (parent[i] != -1)
            cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")\n";
    }
}

//Function to implement Krushkal's algorithm
void Graph::kruskalMST() {
    vector<Edge> edges;
    for (int u = 0; u < V; u++) {
        for (auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            if (u < v) {
                edges.push_back({u, v, w});
            }
        }
    }

    sort(edges.begin(), edges.end());
    makeSet();

    cout << "\nKruskal's MST:\n";
    for (auto& e : edges) {
        if (findSet(e.u) != findSet(e.v)) {
            cout << e.u << " - " << e.v << " (Weight: " << e.weight << ")\n";
            unionSets(e.u, e.v);
        }
    }
}

//Function to implement Dijkstra's algorithm
void Graph::dijkstra(int src) {
    if (src < 0 || src >= V) {
        cout << "Invalid source vertex!\n";
        return;
    }

    vector<int> dist(V, INF);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " -> ";
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << endl;
    }
}