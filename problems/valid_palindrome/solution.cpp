class Solution
{
public:
    bool isPalindrome(string s)
    {
        string rawS = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (isalpha(s[i])|| isdigit(s[i]))
                rawS += tolower(s[i]);
        }
        int l = 0, r = rawS.length() - 1;
        while (l <= r)
        {
            if (rawS[l] != rawS[r])
                return false;
            l++, r--;
        }
        return true;
    }
};