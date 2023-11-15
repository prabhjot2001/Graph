#include <iostream>
#include <vector>
using namespace std;

void printImg(vector<vector<int>> &img)
{
    for (vector<int> i : img)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void dfs(vector<vector<int>> &img1, vector<vector<int>> &visited, int newcolor, int i, int j, int initialColor)
{
    if (i < 0 or j < 0 or i >= img1.size() or j >= img1[0].size())
        return;
    if (img1[i][j] == newcolor and visited[i][j] == 1)
        return;

    if (img1[i][j] == initialColor and visited[i][j] == 0)
    {

        visited[i][j] = 1;
        img1[i][j] = newcolor;

        dfs(img1, visited, newcolor, i + 1, j, initialColor);
        dfs(img1, visited, newcolor, i - 1, j, initialColor);
        dfs(img1, visited, newcolor, i, j + 1, initialColor);
        dfs(img1, visited, newcolor, i, j - 1, initialColor);
    }
}

vector<vector<int>> FloodFill(vector<vector<int>> &img, int sr, int sc, int newcolor)
{
    int row = img.size();
    int col = img[0].size();
    vector<vector<int>> img1 = img;
    vector<vector<int>> visited(row, vector<int>(col));
    int initialColor = img[sr][sc];
    dfs(img1, visited, newcolor, sr, sc, initialColor);
    return img1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int row = 3;
    int col = 3;

    vector<vector<int>> img(row);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int x;
            cin >> x;
            img[i].push_back(x);
        }
    }

    int sr, sc;
    cin >> sr >> sc;

    int newcolor;
    cin >> newcolor;

    vector<vector<int>> ans = FloodFill(img, sr, sc, newcolor);
    printImg(ans);
}