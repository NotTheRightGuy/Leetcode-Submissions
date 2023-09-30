class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        std::unordered_set<int> collected;
        int count = 0;

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (nums[i] <= k)
            {
                collected.insert(nums[i]);
            }
            count++;

            if (collected.size() == k)
            {
                break;
            }
        }

        return (collected.size() == k) ? count : -1;
    }
};