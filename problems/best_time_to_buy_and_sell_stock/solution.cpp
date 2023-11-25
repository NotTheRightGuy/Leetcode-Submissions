class Solution {
public:
    int maxProfit(vector<int> &prices)
{
    int maxMoney = -1e9;
    int lowestSoFar = prices[0];
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < lowestSoFar)
        {
            lowestSoFar = prices[i];
        }
        maxMoney = max(prices[i] - lowestSoFar, maxMoney);
    }
    return maxMoney;
}
};