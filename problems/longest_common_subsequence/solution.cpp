class Solution {
public:
    int longestCommonSubsequence(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    // Base Condition

    // Case 1 when idx1 is 0
    for (int idx2 = 0; idx2 <= n2; idx2++)
    {

        dp[0][idx2] = 0;
    }

    // Case 2 when idx2 is 0
    for (int idx1 = 0; idx1 <= n1; idx1++)
    {
        dp[idx1][0] = 0;
    }

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
                int one = dp[idx1 - 1][idx2];
                int two = dp[idx1][idx2 - 1];
                dp[idx1][idx2] = max(one, two);
            }
        }
    }

    return dp[n1][n2];
}
};