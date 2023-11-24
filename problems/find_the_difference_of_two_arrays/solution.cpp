class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> ans;
        map<int, int> diff1;
        map<int, int> diff2;
        for (int x : nums1)
            diff1[x] = 1;
        for (int y : nums2)
            diff2[y] = 1;
        vector<int> ans1;
        vector<int> ans2;
        for (auto elem : diff1)
        {
            if (!diff2[elem.first])
                ans1.push_back(elem.first);
        }
        for (auto elem : diff2)
        {
            if (!diff1[elem.first])
                ans2.push_back(elem.first);
        }
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};