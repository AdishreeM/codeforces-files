
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = n ? grid[0].size() : 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                ans++;
                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = 0;
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    if (x && grid[x - 1][y] == '1')
                        q.push({x - 1, y}), grid[x - 1][y] = '0';
                    if (y && grid[x][y - 1] == '1')
                        q.push({x, y - 1}), grid[x][y - 1] = '0';
                    if (x + 1 < n && grid[x + 1][y] == '1')
                        q.push({x + 1, y}), grid[x + 1][y] = '0';
                    if (y + 1 < m && grid[x][y + 1] == '1')
                        q.push({x, y + 1}), grid[x][y + 1] = '0';
                }
            }
        }
    }
    return ans;
}