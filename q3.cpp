#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Graph {
private:
    int adjMatrix[100][100];
    int n;
    int time;

public:
    Graph(int n) {
        this->n = n;
        time = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdgeDirected(int u, int v) {
        adjMatrix[u][v] = 1;
    }

    // Perform depth-first search (DFS)
    void DFS(int u, bool visited[], stack<int>& Stack) {
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (adjMatrix[u][v] && !visited[v]) {
                DFS(v, visited, Stack);
            }
        }

        // After visiting all descendants, push the current vertex onto the stack
        Stack.push(u);
    }

    // Perform DFS on the transpose of the graph
    void DFSTranspose(int u, bool visited[], vector<int>& component) {
        visited[u] = true;
        component.push_back(u);

        for (int v = 0; v < n; v++) {
            if (adjMatrix[v][u] && !visited[v]) {
                DFSTranspose(v, visited, component);
            }
        }
    }

    // Find strongly connected components using Tarjan's algorithm
    void SCC() {
        stack<int> Stack;
        bool visited[n];
        for(int i=0;i<n;i++){
           visited[i]=false;
        }

        // Fill vertices in stack according to their finishing times
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(i, visited, Stack);
            }
        }

        // Create a transpose of the graph
        Graph transposedGraph = getTranspose();

        // Mark all the vertices as not visited for the second DFS
        fill_n(visited, n, false);

        // Pop vertices from stack and perform DFS on the transposed graph
        while (!Stack.empty()) {
            int u = Stack.top();
            Stack.pop();

            if (!visited[u]) {
                vector<int> component;
                transposedGraph.DFSTranspose(u, visited, component);
                // Print the strongly connected component
                cout << "Strongly Connected Component: ";
                for (size_t i = 0; i < component.size(); ++i) {
                    int v = component[i];
                    cout << v << " ";
                }
                cout << endl;
            }
        }
    }

    // Get the transpose of the graph
    Graph getTranspose() {
        Graph transposedGraph(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                transposedGraph.adjMatrix[j][i] = adjMatrix[i][j];
            }
        }

        return transposedGraph;
    }
};

int main() {
    cout << "Enter the number of nodes: ";
    int n;
    cin >> n;
    Graph g(n);

    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdgeDirected(u, v);
    }

    cout << "Strongly Connected Components:" << endl;
    g.SCC();

    return 0;
}
