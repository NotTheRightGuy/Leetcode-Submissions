class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        auto max_sum = INT_MIN, sum = 0;
        for (int i = 0; i< nums.size(); i++)
        {
            sum = max(nums[i], sum + nums[i]);
            max_sum = max(max_sum, sum);
        }

        return max_sum;
    }
};