class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
    {
        vector<int> ans;
        ans.reserve(queries.size());
        int q = queries.size();
        int n = points.size();
        for (int i = 0; i < q; i++)
        {
            int centerX = queries[i][0];
            int centerY = queries[i][1];
            int radius = queries[i][2];
            int insidePoints = 0;
            for (auto point : points)
            {
                int pointX = point[0];
                int pointY = point[1];
                insidePoints += (pointX - centerX) * (pointX - centerX) + (pointY - centerY) * (pointY - centerY) <= radius * radius;
            }
            ans.push_back(insidePoints);
        }
        return ans;
    }
};