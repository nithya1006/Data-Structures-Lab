//To  implement Graph ADT with an adjacency list.
#include <iostream>
#include <list>
#include <unordered_map>
#include <string>

using namespace std;

class Graph {
private:
    unordered_map<string, list<string>> adjList;

public:
    void insertEdge(const string&, const string&);
    void deleteEdge(const string&, const string&);
    void searchEdge(const string&, const string&);
    void displayGraph() const;
};

int main() {
    Graph g;
    int choice;
    string src, dest;

    do {
        cout << "\n--- Graph ADT Menu ---\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Search Edge\n";
        cout << "4. Display Graph\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter source vertex: ";
            cin >> src;
            cout << "Enter destination vertex: ";
            cin >> dest;
            g.insertEdge(src, dest);
            break;
        case 2:
            cout << "Enter source vertex: ";
            cin >> src;
            cout << "Enter destination vertex: ";
            cin >> dest;
            g.deleteEdge(src, dest);
            break;
        case 3:
            cout << "Enter source vertex: ";
            cin >> src;
            cout << "Enter destination vertex: ";
            cin >> dest;
            g.searchEdge(src, dest);
            break;
        case 4:
            g.displayGraph();
            break;
        case 5:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

//Function to insert an edge between a source vertex and destination vertex
void Graph::insertEdge(const string& src, const string& dest) {
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
    cout << "Edge inserted between " << src << " and " << dest << ".\n";
}

//Function to delete an edge between a source vertex and destination vertex
void Graph::deleteEdge(const string& src, const string& dest) {
    if (adjList.find(src) == adjList.end() || adjList.find(dest) == adjList.end()) {
        cout << "One or both vertices not found!\n";
        return;
    }
    
    adjList[src].remove(dest);
    adjList[dest].remove(src);
    cout << "Edge deleted between " << src << " and " << dest << ".\n";
}

//Function to search if an edge between a source vertex and destination vertex exists
void Graph::searchEdge(const string& src, const string& dest) {
    if (adjList.find(src) != adjList.end()) {
        for (const auto& neighbor : adjList[src]) {
            if (neighbor == dest) {
                cout << "Edge exists between " << src << " and " << dest << ".\n";
                return;
            }
        }
    }
    cout << "Edge does NOT exist between " << src << " and " << dest << ".\n";
}

//Function to display the graph adjacency list
void Graph::displayGraph() const {
    if (adjList.empty()) {
        cout << "Graph is empty!\n";
        return;
    }
    cout << "Adjacency List of the Graph:\n";
    for (const auto& pair : adjList) {
        cout << pair.first << " -> ";
        for (const auto& neighbor : pair.second) {
            cout << neighbor << " ";
        }
        cout << "\n";
    }
}