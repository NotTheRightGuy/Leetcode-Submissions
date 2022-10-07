class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int countS{0}, countT{0}, check{0};
        while (countT < t.length() && countS != s.length())
        {
            if (t[countT] == s[countS])
            {
                countS++;
            }
            countT++;
        }
        if (countS == s.length())
        {
            return 1;
        }
        return 0;
    }
};