class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0;
        int maxOnes = INT_MIN;
        int zeros = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] == 0)
                zeros++;
            while (zeros > k)
            {
                if (nums[left] == 0)
                    zeros--;
                left++;
            }
            maxOnes = max(maxOnes, right - left + 1);
        }
        return maxOnes;
    }
};