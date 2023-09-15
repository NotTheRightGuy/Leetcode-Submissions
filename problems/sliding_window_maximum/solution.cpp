class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> pq;
        int left = 0;
        int right = k;
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            pq.push(make_pair(nums[i], i));
        }
        while (right <= nums.size())
        {
            while (pq.top().second < left)
            {
                pq.pop();
            }
            ans.push_back(pq.top().first);
            if (right < nums.size())
            {
                pq.push(make_pair(nums[right], right));
            }
            right++;
            left++;
        }
        return ans;
    }
};