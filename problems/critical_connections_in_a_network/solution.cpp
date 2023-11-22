class Solution {
public:
    int timer = 1;
void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, vector<vector<int>> &bridges, int tin[], int low[])
{
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;

    for (auto child : adj[node])
    {
        if (child == parent)
            continue;

        if (!vis[child])
        {
            dfs(child, node, adj, vis, bridges, tin, low);
            low[node] = min(low[node], low[child]);

            if (low[child] > tin[node])
            {
                bridges.push_back({child, node});
            }
        }
        else
        {
            low[node] = min(low[node], low[child]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<int> adj[n];
    for (auto it : connections)
    {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n, 0);
    int tin[n];
    int low[n];
    vector<vector<int>> bridges;
    dfs(0, -1, adj, vis, bridges, tin, low);
    return bridges;
}
};