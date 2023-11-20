class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        vector<vector<int>> finalImage(image);
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        finalImage[sr][sc] = -1;
        q.push({sr, sc});

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m || image[nx][ny] != image[sr][sc] || finalImage[nx][ny] == -1)
                    continue;
                else
                {
                    q.push({nx, ny});
                    finalImage[nx][ny] = -1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (finalImage[i][j] == -1)
                    finalImage[i][j] = color;
            }
        }
        return finalImage;
    }
};