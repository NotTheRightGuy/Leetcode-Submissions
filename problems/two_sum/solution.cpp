class Solution {
public:
vector<int> twoSum(vector<int> nums, int target)
{
    vector<int> res;
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++)
    {
        if (umap.find(target - nums[i]) != umap.end())
        {
            res.push_back(i);
            res.push_back(umap[target - nums[i]]);
            break;
        }
        umap[nums[i]] = i;
    
    }
    return res;
}
};