class Solution {
public:
int maxSubArray(vector<int> &nums)
{
    int currSum = 0, globalSum = INT_MIN;
    for (int i : nums)
    {
        currSum += i;
        globalSum = max(globalSum, currSum);
        if (currSum < 0)
            currSum = 0;
    }
    return globalSum;
}
};