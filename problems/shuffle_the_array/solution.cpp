class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> returnNums;
        for (int i = 0; i < n; i++)
        {
            returnNums.push_back(nums[i]);
            returnNums.push_back(nums[i + n]);
        }
        return returnNums;
    }
};