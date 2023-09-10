class Solution
{
public:
    vector<int> nextGreatestElement(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, -1);
        int maxSoFar = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] > maxSoFar)
            {
                maxSoFar = arr[i];
                ans[i] = -1;
            }
            else
            {
                ans[i] = maxSoFar;
            }
        }
        return ans;
    }
    vector<int> prevGreatestElement(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, -1);
        int maxSoFar = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > maxSoFar)
            {
                maxSoFar = arr[i];
                ans[i] = -1;
            }
            else
            {
                ans[i] = maxSoFar;
            }
        }
        return ans;
    }
    int trap(vector<int> &height)
    {
        vector<int> nge = nextGreatestElement(height);
        vector<int> pge = prevGreatestElement(height);

        int ans = 0;

        for (int i = 0; i < height.size(); i++)
        {
            int minHeight = min(nge[i], pge[i]);
            if (minHeight != -1)
            {
                ans += minHeight - height[i];
            }
        }
        return ans;
    }
};
