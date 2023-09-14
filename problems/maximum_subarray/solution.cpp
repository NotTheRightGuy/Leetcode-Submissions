class Solution {
public:
    int maxSubArray(vector<int> nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    int GLOBAL_MAX = nums[0];
    int LOCAL_MAX = nums[0];
    for (int i = 1; i < n; i++)
    {
        LOCAL_MAX = max(nums[i], LOCAL_MAX + nums[i]);
        GLOBAL_MAX = max(GLOBAL_MAX, LOCAL_MAX);
    }
    return GLOBAL_MAX;
}
};