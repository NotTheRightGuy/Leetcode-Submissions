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
    int removeStones(vector<vector<int>> &stones)
    {
        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet djs = DisjointSet(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;

        for (auto it : stones)
        {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;

            djs.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for (auto it : stoneNodes)
        {
            if (djs.findUpar(it.first) == it.first)
            {
                cnt++;
            }
        }
        return stones.size() - cnt;
    }
};