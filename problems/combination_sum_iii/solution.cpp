class Solution
{
public:
    void solve(int k, int target, int idx, int currSum, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (temp.size() == k)
        {
            if (currSum == target)
                ans.push_back(temp);
            return;
        }
        if (idx > 9)
        {
            if (currSum == target && temp.size() == k)
                ans.push_back(temp);
            return;
        }

        currSum += idx;
        temp.push_back(idx);
        solve(k, target, idx + 1, currSum, temp, ans);

        currSum -= idx;
        temp.pop_back();
        solve(k, target, idx + 1, currSum, temp, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(k, n, 1, 0, temp, ans);
        return ans;
    }
};