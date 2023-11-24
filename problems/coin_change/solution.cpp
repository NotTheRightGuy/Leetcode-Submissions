class Solution {
public:
   int coinChange(vector<int> &coins, int amount)
{
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

    for (int rem = 0; rem <= amount; rem++)
    {
        if (rem % coins[0] == 0)
        {
            dp[0][rem] = rem / coins[0];
        }
        else
            dp[0][rem] = 1e9;
    }

    for (int idx = 1; idx < coins.size(); idx++)
    {
        for (int rem = 0; rem <= amount; rem++)
        {
            int notTake = 0 + dp[idx - 1][rem];
            int take = 1e9;
            if (coins[idx] <= rem)
            {
                take = 1 + dp[idx][rem - coins[idx]];
            }
            dp[idx][rem] = min(notTake, take);
        }
    }

    int ans = dp[coins.size() - 1][amount];
    if (ans == 1e9)
        return -1;
    return ans;
}
};