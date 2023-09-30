class Solution
{
public:
    int maxSubarrays(const std::vector<int> &nums)
    {
        int minAnd = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            minAnd &= nums[i];
        }
        if(minAnd != 0) return 1;
        int maxSubArrays = 0;
        int currAnd = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (currAnd == minAnd)
            {
                maxSubArrays++;
                currAnd = nums[i];
            }
            currAnd &= nums[i];
        }
        if (currAnd == minAnd)
        {
            maxSubArrays++;
        }
        return maxSubArrays;
    }
};