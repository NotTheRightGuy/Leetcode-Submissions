class Solution
{
public:
    bool isValid(string s)
    {
        stack<int> ps;
        for (int i = 0; i < s.length(); i++)
        {
            if (!ps.empty())
            {
                if (ps.top() == '(' && s[i] == ')')
                    ps.pop();
                else if (ps.top() == '[' && s[i] == ']')
                    ps.pop();
                else if (ps.top() == '{' && s[i] == '}')
                    ps.pop();
                else
                {
                    ps.push(s[i]);
                }
            }
            else
            {
                ps.push(s[i]);
            }
        }
        if (ps.empty())
            return true;
        else
            return false;
    }
};