class Solution {
public:
int longestConsecutive(vector<int> &nums)
{
    set<int> hashSet(nums.begin(), nums.end());
    int longestStreak = 0;
    for (int num : nums)
    {
        if (!hashSet.count(num - 1))
        {
            int currentNum = num;
            int currentStreak = 1;
            while (hashSet.count(currentNum + 1))
            {
                currentNum++;
                currentStreak++;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}
};