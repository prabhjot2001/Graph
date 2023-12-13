#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// problem number of proviences

void addEdge(vector<int> graph[], int src, int dest)
{
    graph[src].push_back(dest);
    graph[dest].push_back(src);
}

void BFS(int visited[], vector<int> graph[], int start)
{
    queue<int> q;
    visited[start] = 1;
    q.push(start);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        visited[node] = 1;
        for (auto i : graph[node])
        {
            if (visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

void DFS(int visited[], vector<int> graph[], int start)
{
    visited[start] = 1;
    for (auto i : graph[start])
    {
        if (visited[i] == 0)
        {
            DFS(visited, graph, i);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int V, E;
    cin >> V >> E;

    vector<int> graph[V];
    int visited[V] = {0};

    for (int i = 0; i < E; i++)
    {
        int src, dest;
        cin >> src >> dest;
        addEdge(graph, src, dest);
    }

    int counter = 0;
    for (int i = 1; i <= V; i++)
    {
        if (visited[i] == 0)
        {
            // BFS(visited, graph, i);
            DFS(visited, graph, i);
            counter++;
        }
    }
    cout << "Number of proviences - " << counter << endl;
}