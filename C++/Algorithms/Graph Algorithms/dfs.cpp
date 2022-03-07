#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void displayAdjacencyList(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

void DFSRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (int u : adj[s])
    {
        if (visited[u] == false)
            DFSRec(adj, u, visited);
    }
}

// If source is given and it is a connected graph
void DFS(vector<int> adj[], int v, int s)
{
    bool visited[v + 1] = {false};
    DFSRec(adj, s, visited);
}

// Disconnected Graph
void DFS(vector<int> adj[], int v)
{
    bool visited[v + 1] = {false};
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
            DFSRec(adj, i, visited);
    }
}

int countDisconnectComponents(vector<int> adj[], int v)
{
    bool visited[v + 1] = {false};
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            DFSRec(adj, i, visited);
            count++;
        }
    }
    return count;
}

int main()
{
    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 4);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 5);
    addEdge(adj, 5, 3);
    addEdge(adj, 5, 4);
    DFS(adj, v);

    // int V, E;
    // cin >> V >> E;
    // vector<int> adj[V];
    // for (int i = 0; i < E; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     addEdge(adj, u, v);
    // }

    return 0;
}
