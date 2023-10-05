class Solution
{
public:
    bool canJump(vector<int> nums)
    {
        int maxBlock = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (i > maxBlock)
                return false;
            maxBlock = max(maxBlock, i + nums[i]);
        }
        return true;
    }
};