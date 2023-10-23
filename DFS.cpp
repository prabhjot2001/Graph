#include <iostream>
#include <vector>
using namespace std;

vector<int> dfs;

void printVector(vector<int>v)
{ 
    cout<<"DFS is:- ";
   for(auto i: v)
   {
    cout<<i<<" ";
   }
}

void addEdge(vector<int> adjList[], int src, int dest)
{
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

void depth_first_search(int node, int visited[], vector<int> adjList[])
{ 
    for (auto i : adjList[node])
    {
        if (visited[i] == 0)
        {
            dfs.push_back(i);
            visited[i] = 1;
            depth_first_search(i, visited, adjList);
        }
    }
}

void DFS(int n, int start, vector<int> adjList[])
{
    int visited[n] = {0};
    visited[start] = 1;
    dfs.push_back(start);
    depth_first_search(start, visited, adjList);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int v, e, start;
    int check;
    cout<<"Is your graph 0 based index or 1 based index, please enter 0 or 1 accordingly";
    cin>>check;
    cout << "Enter no. of Nodes ";
    cin >> v;
    cout << "Enter no. of Edges ";
    cin >> e;

    if(check== 1)
    {
       v+= 1;
    }
    
    vector<int> adjList[v];
    for (int i = 0; i < e; i++)
    {
        int s, d;
        cin >> s >> d;
        addEdge(adjList, s, d);
    }

    cout << "Enter starting point ";
    cin >> start;

    DFS(v, start, adjList);

    printVector(dfs);
}