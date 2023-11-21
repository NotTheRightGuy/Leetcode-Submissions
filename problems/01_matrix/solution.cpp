class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> visited(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        while (!q.empty())
        {
            auto child = q.front();
            q.pop();
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            for (int i = 0; i < 4; i++)
            {
                int nx = child.first.first + dx[i];
                int ny = child.first.second + dy[i];
                if (nx >= n || ny >= m || nx < 0 || ny < 0 || visited[nx][ny] == 1)
                    continue;
                if (mat[nx][ny] == 0)
                {
                    ans[nx][ny] = 0;
                    q.push({{nx, ny}, 0});
                }
                else
                {
                    ans[nx][ny] = child.second + 1;
                    q.push({{nx, ny}, child.second + 1});
                }
                visited[nx][ny] = 1;
            }
        }
        return ans;
    }
};
