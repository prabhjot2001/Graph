#include <bits/stdc++.h>
using namespace std;

/*
  0 = empty
  1 = fresh
  2 = rotten
*/
int rotTommato(int level, vector<vector<int>> &crate, int i, int j, vector<vector<int>> &visited, queue<pair<pair<int, int>, int>> &que)
{
    if (i < 0 and j < 0 and i >= crate.size() and j >= crate[0].size())
        return 0;

    if (crate[i][j] == 2)
    {
        return 0;
    }

    if (visited[i][j] == 0 and crate[i][j] == 1)
    {
        visited[i][j] = 1;
        crate[i][j] = 2;
        que.push({{i, j}, level});
        return 1;
    }
    return 0;
}

void bfs(vector<vector<int>> &crate, queue<pair<pair<int, int>, int>> &que, int count, vector<vector<int>> &visited)
{
    int level = 0;

    int count = 1;
    while (!que.empty())
    {
        pair<pair<int, int>, int> pr = que.front();
        que.pop();

        int i = pr.first.first;
        int j = pr.first.second;
        visited[i][j] = 1;

        if (rotTommato(level, crate, i + 1, j, visited, que))
        {
            count++;
        };
        if (rotTommato(level, crate, i, j + 1, visited, que))
        {
            count++;
        };
        if (rotTommato(level, crate, i - 1, j, visited, que))
        {
            count++;
        };
        if (rotTommato(level, crate, i, j - 1, visited, que))
        {
            count++;
        };
    }
}

void RottenOranges(vector<vector<int>> &crate)
{
    int row = crate.size();
    int col = crate[0].size();
    int count = 0;
    queue<pair<pair<int, int>, int>> que; // { {row,col}, count }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (crate[i][j] == 2)
            {
                que.push({{i, j}, count});
            }
        }
    }

    vector<vector<int>> visited(row, vector<int>(col));

    bfs(crate, que, count, visited);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int row = 3;
    int col = 3;

    vector<vector<int>> crate(row);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int x;
            cin >> x;
            crate[i].push_back(x);
        }
    }

    RottenOranges(crate);
}