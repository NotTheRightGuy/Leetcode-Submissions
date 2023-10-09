class Solution
{
public:
    int lowerBound(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid;
        int lastIndex = -1;
        while (low <= high)
        {
            mid = low + (high - low / 2);
            if (nums[mid] == target)
            {
                lastIndex = mid;
                high = mid - 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return lastIndex;
    }

    int upperBound(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid;
        int lastIndex = -1;
        while (low <= high)
        {
            mid = low + (high - low / 2);
            if (nums[mid] == target)
            {
                lastIndex = mid;
                low = mid + 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return lastIndex;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        ans.push_back(lowerBound(nums, target));
        ans.push_back(upperBound(nums, target));
        return ans;
    }
};
