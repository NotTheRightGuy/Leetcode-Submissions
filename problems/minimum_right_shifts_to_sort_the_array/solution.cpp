class Solution
{
public:
    int minimumRightShifts(vector<int> &nums)
    {
        int n = nums.size();
        int breakValue = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                breakValue++;
            }
        }
        if (nums[n - 1] > nums[0])
            breakValue++;

        if (breakValue <= 1)

        {
            for (int i = 0; i < n - 1; i++)
            {
                if (nums[i] > nums[i + 1])
                {
                    return n - 1 - i;
                }
            }
            return 0;
        }
        return -1;
    }
};