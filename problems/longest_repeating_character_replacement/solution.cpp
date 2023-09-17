class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        map<int, int> mp;
        int left = 0;
        int maxFreq = INT_MIN;
        int ans = INT_MIN;
        for (int right = 0; right < s.length(); right++)
        {
            mp[s[right]]++;
            maxFreq = max(maxFreq, mp[s[right]]);

            while (right - left + 1 - maxFreq > k)
            {
                mp[s[left]]--;
                left++;
            }

            ans = max(right - left + 1, ans);
        }
        return ans;
    }
};