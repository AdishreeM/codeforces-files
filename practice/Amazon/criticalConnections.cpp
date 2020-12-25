#include <bits\stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;

class graph
{
    map<int, VI> edges;
    VB visited;
    VI low;
    VI tin;
    int time;
    VVI bridges;

public:
    void dfs(int node, int parent = -1)
    {
        low[node] = tin[node] = time++;
        visited[node] = true;
        for (auto child : edges[node])
        {
            if (child == parent)
                continue;
            if (visited[child])
                low[node] = min(tin[child], low[node]);
            else
            {
                dfs(child, node);
                low[node] = min(low[node], low[child]);
                if (low[child] > tin[node])
                {
                    bridges.push_back({node, child});
                    bridges.push_back({child, node});
                }
            }
        }
    }

    VVI getBridges(int nodes, VVI connection)
    {
        edges.clear();
        set<VI> given;
        for (auto connect : connection)
        {
            given.insert(connect);
            edges[connect[0]].push_back(connect[1]);
            edges[connect[1]].push_back(connect[0]);
        }
        visited = vector<bool>(nodes, false);
        low = tin = vector<int>(nodes, -1);
        time = 0;
        for (int i = 1; i <= nodes; i++)
        {
            if (!visited[i])
                dfs(i);
        }
        VVI ans;
        for (auto bridge : bridges)
        {
            if (given.find(bridge) != given.end())
                ans.push_back(bridge);
        }
        return ans;
    }
};

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    int numNodes = 5;
    VVI edges = {{1, 2}, {1, 3}, {3, 4}, {1, 4}, {5, 4}};
    graph G;
    VVI ans = G.getBridges(numNodes, edges);
    for (auto edge : ans)
        cout << edge[0] << ' ' << edge[1] << endl;
    return 0;
}