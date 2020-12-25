#include <bits/stdc++.h>
using namespace std;

int StepsToTreasure(vector<vector<char>> island)
{
    int n = island.size();
    if (n == 0)
        return -1;
    int m = island[0].size();
    queue<vector<int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (island[i][j] == 'S')
                q.push({i, j, 0}), island[i][j] == 'D';
    vector<int> neighbour = {0, -1, 0, 1, 0};
    while (!q.empty())
    {
        auto top = q.front();
        int x = top[0], y = top[1], t = top[2];
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int r = neighbour[i], c = neighbour[i + 1];
            if (x + r >= 0 && x + r < n && y + c >= 0 && y + c < m)
            {
                if (island[x + r][y + c] == 'X')
                    return t + 1;
                if (island[x + r][y + c] != 'D')
                {
                    q.push({x + r, y + c, t + 1});
                    island[x + r][y + c] = 'D';
                }
            }
        }
    }
    return -1;
}

int main()
{
    vector<vector<char>> island = {{'S', 'O', 'O', 'S', 'S'},
                                   {'D', 'O', 'D', 'O', 'D'},
                                   {'O', 'O', 'O', 'O', 'D'},
                                   {'D', 'O', 'D', 'O', 'D'},
                                   {'S', 'X', 'D', 'D', 'D'}};
    cout << StepsToTreasure(island);
}