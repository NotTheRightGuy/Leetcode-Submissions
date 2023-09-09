class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < (1 << nums.size()); i++)
        {
            vector<int> temp;
            int idx = 0;
            int temp_i = i;
            while (temp_i > 0)
            {
                if (temp_i & 1)
                {
                    temp.push_back(nums[idx]);
                }
                temp_i = temp_i >> 1;
                idx++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};