#include <iostream>
#include <queue>
using namespace std;

class Graph {
private:
    int n;
    int adjList[100][100]; // Use a fixed size for the adjacency list

public:
    Graph(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adjList[i][j] = 0; // Initialize all elements to 0
            }
        }
    }

    void addEdgeDirected(int u, int v) {
        adjList[u][v] = 1;
    }

    void addEdgeUndirected(int u, int v) {
        adjList[u][v] = 1;
        adjList[v][u] = 1;
    }

    // Getter method to access the number of nodes
    int getNumNodes() {
        return n;
    }

    // Getter method to access the adjacency list of a node
    int* getAdjList(int u) {
        return adjList[u];
    }

    void inputGraph() {
        int numEdges;
        cout << "Enter the number of edges: ";
        cin >> numEdges;
        cout << "Enter the edges (u v):" << endl;
        for (int i = 0; i < numEdges; ++i) {
            int u, v;
            cin >> u >> v;
            addEdgeUndirected(u, v);
            // addEdgeDirected(u,v);
        }
    }

    void displayAdjacentList() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < n; ++i) {
            cout << i << "->";
            for (int j = 0; j < n; ++j) {
                if (adjList[i][j] == 1) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
};

void BFS(Graph g, int start, bool visited[]) {
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        cout << current << " ";
        q.pop();

        int* adjNodes = g.getAdjList(current); // Get the adjacency list for current node

        for (int i = 0; i < g.getNumNodes(); i++) {
            if (adjNodes[i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    cout << "Enter the number of nodes: ";
    int n;
    cin >> n;
    Graph g(n);
    g.inputGraph();

    // Initialize visited array
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }

    g.displayAdjacentList();

    // Perform BFS starting from node 0
    cout << "BFS (starting from node 0): ";
    BFS(g, 0, visited);

    return 0;
}
