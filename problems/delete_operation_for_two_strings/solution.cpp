class Solution {
public:
    int util(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int idx1 = 1; idx1 <= n1; idx1++)
    {
        for (int idx2 = 1; idx2 <= n2; idx2++)
        {
            if (s1[idx1 - 1] == s2[idx2 - 1])
            {
                dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
            }
            else
            {
                int option1 = dp[idx1 - 1][idx2];
                int option2 = dp[idx1][idx2 - 1];
                dp[idx1][idx2] = max(option1, option2);
            }
        }
    }

    return dp[n1][n2];
}

int minDistance(string word1, string word2)
{
    int f = util(word1, word2);
    int n = word1.size();
    int m = word2.size();
    return (n-f) + (m-f);
}
};