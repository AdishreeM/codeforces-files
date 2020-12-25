#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

class graph
{

    VI parent;
    VI rank;
    int component;

    int find(int v)
    {
        if (parent[v] != v)
            parent[v] = find(parent[v]);
        return parent[v];
    }

    void connect(int v1, int v2)
    {
        int root1 = find(v1);
        int root2 = find(v2);
        if (root1 == root2)
            return;
        if(rank[root1] < rank[root2])
            swap(root1, root2);    
        parent[root2] = root1;
        rank[root1] += (rank[root1] == rank[root2] ? 1 : 0);
        --component;
    }

    bool isConnected(int v1, int v2)
    {
        return find(v1) == find(v2);
    }

public:
    int minCosttoConnectAllNodes(int n, VVI edges, VVI newEdges)
    {
        parent = vector<int>(n + 1);
        rank = vector<int>(n+1, 0);
        component = n;
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
        for (VI edge : edges)
            connect(edge[0], edge[1]);
        sort(newEdges.begin(), newEdges.end(), [](VI a, VI b) {
            return a[2] < b[2];
        });
        int cost = 0;
        for (int i = 0; i < newEdges.size(); ++i)
        {
            if (component == 1)
                return cost;
            if (!isConnected(newEdges[i][0], newEdges[i][1]))
            {
                connect(newEdges[i][0], newEdges[i][1]);
                cost += newEdges[i][2];
            }
        }
        return -1;
    }
};

int main()
{
    int n = 6;
    VVI edges = {};
    VVI newEdges = {};
    graph G;
    cout << G.minCosttoConnectAllNodes(n, edges, newEdges);
    return 0;
}