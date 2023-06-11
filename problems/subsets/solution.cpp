class Solution
{
public:
    void generate(vector<int> &nums, int i, vector<int> &subset,vector<vector<int>> &all)
    {
        if (i == nums.size()){
            all.push_back(subset);
            return;
        }
        generate(nums, i + 1, subset,all);
        subset.push_back(nums[i]);
        generate(nums, i + 1, subset,all);
        subset.pop_back();
    }

    vector<vector<int>> subsets(vector<int> nums)
    {
        vector<int> subset;
        vector<vector<int>> all;
        generate(nums, 0, subset,all);
        return all;
    }
};