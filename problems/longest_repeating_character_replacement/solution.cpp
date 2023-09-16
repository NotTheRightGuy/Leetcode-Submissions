class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        map<char, int> mp;
        int ans = INT_MIN;
        int left = 0;
        int maxInWindow = 0;
        for (int right = 0; right < s.length(); right++)
        {
            mp[s[right]]++;
            maxInWindow = max(maxInWindow, mp[s[right]]);

            if (right - left + 1 - maxInWindow > k)
            {
                mp[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};