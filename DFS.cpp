#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    void dfs(vector<int> adj[], bool *vis, int start, vector<int> &ans)
    {
        vis[start] = 1;
        ans.push_back(start);
        for (auto it : adj[start])
        {
            if (!vis[it])
            {
                vis[it] = true;
                dfs(adj, vis, it, ans);
            }
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> ans;
        bool vis[V] = {0};
        int start = 0;
        dfs(adj, vis, start, ans);
        return ans;
    }
};