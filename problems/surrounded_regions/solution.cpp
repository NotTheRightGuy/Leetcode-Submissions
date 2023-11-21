class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        stack<pair<int, int>> s;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
            {
                s.push({i, 0});
                visited[i][0] = 1;
                board[i][0] = 'm';
            }

            if (board[i][m - 1] == 'O')
            {
                s.push({i, m - 1});
                visited[i][m - 1] = 1;
                board[i][m - 1] = 'm';
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (board[0][i] == 'O')
            {
                s.push({0, i});
                visited[0][i] = 1;
                board[0][i] = 'm';
            }

            if (board[n - 1][i] == 'O')
            {
                s.push({n - 1, i});
                visited[n - 1][i] = 1;
                board[n - 1][i] = 'm';
            }
        }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!s.empty())
        {
            auto top = s.top();
            s.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = top.first + dx[i];
                int ny = top.second + dy[i];

                if (nx >= n || ny >= m || nx < 0 || ny < 0 || visited[nx][ny] == 1)
                    continue;

                if (board[nx][ny] == 'O')
                {
                    s.push({nx, ny});
                    board[nx][ny] = 'm';
                }

                visited[nx][ny] = 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'm')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};