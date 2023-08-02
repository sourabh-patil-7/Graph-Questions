#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution
{

private:
    void dfs(vector<int> adj[], int start, bool *vis)
    {
        vis[start] = 1;
        for (auto it : adj[start])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                dfs(adj, it, vis);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        vector<int> adjLs[V + 1];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (i != j && adj[i][j] == 1)
                {
                    adjLs[i + 1].push_back(j + 1);
                }
            }
        }
        int count = 0;
        bool vis[V + 1] = {0};
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                count++;
                dfs(adjLs, i, vis);
            }
        }
        return count;
    }
};