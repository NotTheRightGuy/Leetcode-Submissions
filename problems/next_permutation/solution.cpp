class Solution {
public:
   void nextPermutation(vector<int> &nums)
{
    int firstPeak;
    int firstValLargerThanFirstPeak;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            firstPeak = i;
            break;
        }
    }
    if (firstPeak < 0)
        reverse(nums.begin(), nums.end());
    else
    {
        for (int i = nums.size() - 1; i >= firstPeak; i--)
        {
            if (nums[i] > nums[firstPeak])
            {
                firstValLargerThanFirstPeak = i;
                break;
            }
        }
        swap(nums[firstPeak], nums[firstValLargerThanFirstPeak]);
        reverse(nums.begin() + firstPeak + 1, nums.end());
    }
}
};