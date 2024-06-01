#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int adjMatrix[100][100];
    int n;

public:
    Graph(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdgeUndirected(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void addEdgeDirected(int u, int v) {
        adjMatrix[u][v] = 1;
    }

    void computeDegrees() {
        for (int i = 0; i < n; ++i) {
            int indegree = 0;
            int outdegree = 0;

            // Compute indegree
            for (int j = 0; j < n; ++j) {
                indegree += adjMatrix[j][i];
            }

            // Compute outdegree
            for (int j = 0; j < n; ++j) {
                outdegree += adjMatrix[i][j];
            }

            // Print indegree and outdegree of node i
            cout << "Node " << i << ": Indegree = " << indegree << ", Outdegree = " << outdegree << endl;
        }
    }

    void displayAdjacencyMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void inputGraph() {
        int numEdges;
        cout << "Enter the number of edges: ";
        cin >> numEdges;
        cout << "Enter the edges (u v):" << endl;
        for (int i = 0; i < numEdges; ++i) {
            int u, v;
            cin >> u >> v;
            // addEdgeDirected(u, v);
            addEdgeUndirected(u,v);
        }   
    }
    void displayAdjacentList() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < n; ++i) {
            cout << i << "->";
            for (int j = 0; j < n; ++j) {
                if (adjMatrix[i][j] == 1) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "Enter the number of nodes: ";
    int n;
    cin >> n;
    Graph g(n);
    g.inputGraph();

    g.computeDegrees();
    g.displayAdjacencyMatrix();
    g.displayAdjacentList();

    return 0;
}
