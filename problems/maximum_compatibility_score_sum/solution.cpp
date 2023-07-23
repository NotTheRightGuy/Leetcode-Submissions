#define all(x) x.begin(), x.end()

class Solution
{
public:
    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors)
    {
        int n = students.size();
        int m = students[0].size();
        vector<int> perm(n);
        for (int i = 0; i < n; i++)
            perm[i] = i;
        int ans = 0;
        do
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                int cnt = 0;
                for (int j = 0; j < m; j++)
                    if (students[i][j] == mentors[perm[i]][j])
                        cnt++;
                sum += cnt;
            }
            ans = max(ans, sum);
        } while (next_permutation(all(perm)));
        return ans;
    }
};