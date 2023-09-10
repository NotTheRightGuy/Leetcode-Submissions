class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums2.size();
        vector<int> tempArr(n, -1);
        stack<int> s;
        s.push(nums2[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            while (!s.empty() && nums2[i] >= s.top())
            {
                s.pop();
            }
            if (!s.empty() && s.top() > nums2[i])
            {
                tempArr[i] = s.top();
            }
            s.push(nums2[i]);
        }
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums2[i]] = tempArr[i];
        }
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};