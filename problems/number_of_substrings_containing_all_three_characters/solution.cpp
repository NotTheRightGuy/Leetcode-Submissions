class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int cnt = 0;
        int idx_a{-1}, idx_b{-1}, idx_c{-1};

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a')
                idx_a = i;
            else if (s[i] == 'b')
                idx_b = i;
            else
                idx_c = i;

            if (i > 1)
            {
                cnt += min(min(idx_a, idx_b), min(idx_b, idx_c)) + 1;
            }
        }
        return cnt;
    }
};