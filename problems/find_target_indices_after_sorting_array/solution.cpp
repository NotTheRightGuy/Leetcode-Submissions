class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int lb = lower_bound(nums.begin(), nums.end(),target) - nums.begin();
        int up = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(lb == up) return {};
        vector<int> ans;
        while(lb < up) ans.push_back(lb++);
        return ans;
    }
};