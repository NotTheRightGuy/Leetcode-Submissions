class DisjointSet
{
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUpar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]); // Path compression
    }

    bool sameParent(int u, int v)
    {
        return findUpar(u) == findUpar(v);
    }

    void unionBySize(int u, int v)
    {
        if (sameParent(u, v))
            return;

        int uPar = findUpar(u);
        int vPar = findUpar(v);

        if (size[uPar] < size[vPar])
        {
            parent[uPar] = vPar;
            size[vPar] += size[uPar];
        }
        else
        {
            parent[vPar] = uPar;
            size[uPar] += size[vPar];
        }
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        DisjointSet djs = DisjointSet(n);
        int totalAvailable = connections.size();
        for (auto it : connections)
        {
            int u = it[0];
            int v = it[1];
            if (djs.sameParent(u, v))
                continue;
            djs.unionBySize(u, v);
            totalAvailable--;
        }
        set<int> enclave;
        for (int i = 0; i < n; i++)
        {
            if (djs.findUpar(i) == i)
            {
                enclave.insert(i);
            }
        }
        if (enclave.size() - 1 <= totalAvailable)
            return enclave.size() - 1;
        return -1;
    }
};