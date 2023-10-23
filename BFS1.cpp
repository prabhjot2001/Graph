#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<int>adjList[], int s, int d){
      adjList[s].push_back(d);
      adjList[d].push_back(s);
}

void printVector(vector<int>v)
{
   for(auto i: v)
   {
    cout<<i<<" ";
   }
}

void bfs(int n, int start, vector<int>adjList[])
{
  bool visited[n] = {false};
  queue<int> q;
  visited[start] = true;
  vector<int>BFS;
  q.push(start);
  while(!q.empty())
  {
     int node = q.front();
     BFS.push_back(node);
     q.pop();
     for(auto i: adjList[node])
     {
      if(visited[i] == false)
      {
          visited[i] = true;
          q.push(i);
      }
     } 
  }
  printVector(BFS);
}
int main()
{
  int V = 10;
  vector<int> adjList[V];
  addEdge(adjList,1,2);
  addEdge(adjList,1,6);
  addEdge(adjList,2,3);
  addEdge(adjList,6,9);
  addEdge(adjList,2,4);
  addEdge(adjList,6,7);
  addEdge(adjList,4,5);
  addEdge(adjList,7,8);
  addEdge(adjList,5,8);
  int start = 8;
  bfs(V, start, adjList);
}