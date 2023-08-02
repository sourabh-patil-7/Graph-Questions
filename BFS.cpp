#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.

    vector<int> BFS(vector<int> adj[], bool vis[])
    {
        vector<int> ans;
        queue<int> q;
        q.push(0);
        vis[0] = true;
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            ans.push_back(top);

            for (auto it : adj[top])
            {
                if (!vis[it])
                {
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        return ans;
    }

    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        bool vis[V] = {0};
        vector<int> ans = BFS(adj, vis);
        return ans;
    }
};