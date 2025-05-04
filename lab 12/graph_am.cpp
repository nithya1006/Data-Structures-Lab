//To implement Graph ADT with an adjacency matrix
#include <iostream>
using namespace std;
#define MAX_VERTICES 20

class Graph {
private:
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;

    bool isValidVertex(int v) {
        return v >= 0 && v < numVertices;
    }
public:
    Graph(int vertices) {
        if (vertices > MAX_VERTICES || vertices <= 0) {
            cout << "Invalid number of vertices. Setting to 0.\n";
            numVertices = 0;
        } else {
            numVertices = vertices;
        }
        for (int i = 0; i < MAX_VERTICES; i++) {
            for (int j = 0; j < MAX_VERTICES; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void insertEdge(int, int);
    void deleteEdge(int, int);
    void searchEdge(int, int);
    void display();
};

int main() {
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    Graph g(vertices);
    int choice;
    do {
        cout << "\n--- Graph Menu ---\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Search Edge\n";
        cout << "4. Display Graph\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int src, dest;
        switch (choice) {
            case 1:
                cout << "Enter source and destination vertices to insert edge: ";
                cin >> src >> dest;
                g.insertEdge(src, dest);
                break;

            case 2:
                cout << "Enter source and destination vertices to delete edge: ";
                cin >> src >> dest;
                g.deleteEdge(src, dest);
                break;

            case 3:
                cout << "Enter source and destination vertices to search edge: ";
                cin >> src >> dest;
                g.searchEdge(src, dest);
                break;

            case 4:
                g.display();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

//Function to insert an edge between a source vertex and destination vertex
void Graph::insertEdge(int src, int dest) {
    if (isValidVertex(src) && isValidVertex(dest)) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1; // For undirected graph
        cout << "Edge inserted between " << src << " and " << dest << ".\n";
    } else {
        cout << "Invalid vertices.\n";
    }
}

//Function to delete an edge between a source vertex and destination vertex
void Graph::deleteEdge(int src, int dest) {
    if (isValidVertex(src) && isValidVertex(dest)) {
        if (adjMatrix[src][dest] == 1) {
            adjMatrix[src][dest] = 0;
            adjMatrix[dest][src] = 0;
            cout << "Edge deleted between " << src << " and " << dest << ".\n";
        } else {
            cout << "No edge exists between " << src << " and " << dest << ".\n";
        }
    } else {
        cout << "Invalid vertices.\n";
    }
}

//Function to search if an edge between a source vertex and destination vertex exists
void Graph::searchEdge(int src, int dest) {
    if (isValidVertex(src) && isValidVertex(dest)) {
        if (adjMatrix[src][dest] == 1) {
            cout << "Edge exists between " << src << " and " << dest << ".\n";
        } else {
            cout << "No edge exists between " << src << " and " << dest << ".\n";
        }
    } else {
        cout << "Invalid vertices.\n";
    }
}

//Function to display the graph adjacency matrix
void Graph::display() {
    cout << "\nAdjacency Matrix:\n";
    cout << "   ";
    for (int i = 0; i < numVertices; i++) {
        cout << i << " ";
    }
    cout << "\n";
    for (int i = 0; i < numVertices; i++) {
        cout << i << ": ";
        for (int j = 0; j < numVertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}