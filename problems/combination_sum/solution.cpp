class Solution {
public:
void solve(int idx, vector<int> &arr, int target, int currSum, vector<int> &temp, vector<vector<int>> &ans)
{
    if (idx == arr.size() || currSum >= target)
    {
        if (currSum == target)
        {
            ans.push_back(temp);
        }
        return;
    }
    temp.push_back(arr[idx]);
    currSum += arr[idx];
    solve(idx, arr, target, currSum, temp, ans);

    temp.pop_back();
    currSum -= arr[idx];
    solve(idx + 1, arr, target, currSum, temp, ans);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,candidates,target,0,temp,ans);
        return ans;
    }
};