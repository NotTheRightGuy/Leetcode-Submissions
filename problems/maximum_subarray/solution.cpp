class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int localMax = 0;
        int globalMax = INT_MIN;
        for (int i : nums)
        {
            localMax += i;
            globalMax = max(localMax, globalMax);
            if (localMax < 0)
                localMax = 0;
        }
        return globalMax;
    }
};