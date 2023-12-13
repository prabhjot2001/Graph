#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void recursive(vector<vector<int>> &grid, int i, int j)
{
    // checking the boundary conditions
    if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size())
        return;
    if (grid[i][j] == 0)
        return;
    grid[i][j] = 0;
    recursive(grid, i + 1, j);
    recursive(grid, i - 1, j);
    recursive(grid, i, j + 1);
    recursive(grid, i, j - 1);
}

void bfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int i, int j)
{
    queue<pair<int, int>> q;
    visited[i][j] = 1;
    q.push({i, j});

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;

        q.pop();

        for (int ik = -1; ik <= 1; ik++)
        {
            for (int jk = -1; jk <= 1; jk++)
            {
                int nrow = row + ik;
                int ncol = col + jk;

                if (nrow >= 0 and ncol >= 0 and ncol < grid[0].size() and nrow < grid.size() and visited[nrow][ncol] == 0 and grid[nrow][ncol] == 1)
                {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}

int numOfIslands(vector<vector<int>> &grid)
{
    int counter = 0;

    int row = grid.size();
    int col = grid[0].size();

    vector<vector<int>> visited(row, vector<int>(col, 0));
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            // if (grid[i][j] == 1)
            // {
            //     recursive(grid, i, j);
            //     counter++;
            // }
            if (visited[i][j] == 0 and grid[i][j] == 1)
            {
                bfs(grid, visited, i, j);
                counter++;
            }
        }
    }
    return counter;
}

int main()
{
    vector<vector<int>> grid = {
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 1}};

    cout << numOfIslands(grid);
}