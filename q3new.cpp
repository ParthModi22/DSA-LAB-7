#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void addEdge(vector<vector<int> > &adj, int u, int v)
{
    adj[u].push_back(v);
}

void transposeGraph(vector<vector<int> > adj, vector<vector<int> > &adjT)
{
    int V = adj.size();
    for (int v = 0; v < V; ++v)
    {
        for (int i = 0; i < adj[v].size(); ++i)
        {
            adjT[adj[v][i]].push_back(v);
        }
    }
}

void dfs2(int a, vector<bool> &visited, vector<vector<int> > &adj)
{
    cout << a << " ";
    // cout << a ;
    // cout << "hi\n";

    visited[a] = true;

    for (int i = 0; i < adj[a].size(); i++)
    {
        int y = adj[a][i];
        if (!visited[y])
        {
            dfs2(y, visited, adj);
        }
    }
    // s.push(a); // we want to push last node first
    return;
}

void dfs1(int a, vector<bool> &visited, vector<vector<int> > &adj, stack<int> &s)
{
    // cout << a << " ";
    visited[a] = true;

    for (int i = 0; i < adj[a].size(); i++)
    {
        int y = adj[a][i];
        if (!visited[y])
        {
            dfs1(y, visited, adj, s);
        }
    }
    s.push(a); // we want to push last node first
    return;
}

void printSCCs(vector<vector<int> > adj)
{
    int V = adj.size();
    stack<int> s;
    vector<bool> visited(V, false);

    for (int v = 0; v < V; ++v)
    {
        if (!visited[v])
        {
            dfs1(v, visited, adj, s);
        }
    }

    // create transpose

    vector<vector<int> > adjT(V);
    transposeGraph(adj, adjT);

    for (int i = 0; i < V; i++)
    {
        visited[i] = false; // reset it for 2nd DFS
    }

    while (!s.empty())
    {
        int x = s.top();
        s.pop();

        if (!visited[x])
        {
            dfs2(x, visited, adjT);
            cout << endl;
        }
    }
}

int main()
{
    cout << endl;

    int V;
    // cin >> V;
    V = 10;

    vector<vector<int> > adj(V);

    // bool visited[adj.size()] = {false};

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);
    addEdge(adj, 6, 7);
    addEdge(adj, 7, 8);
    addEdge(adj, 8, 9);
    addEdge(adj, 9, 8);
    // dfs1(0, visited, adj);
    printSCCs(adj);

    cout << endl
         << endl;
    return 0;
}