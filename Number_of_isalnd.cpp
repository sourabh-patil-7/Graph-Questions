#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
public:
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int row, int col, int n, int m)
    {
        vis[row][col] = 1;

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int newrow = row + i;
                int newcol = col + j;
                if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && (i != 0 || j != 0) && grid[newrow][newcol] == '1' && !vis[newrow][newcol])
                {
                    vis[newrow][newcol] = 1;
                    dfs(grid, vis, newrow, newcol, n, m);
                }
            }
        }
    }

    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    count++;
                    dfs(grid, vis, i, j, n, m);
                }
            }
        }
        return count;
    }
};