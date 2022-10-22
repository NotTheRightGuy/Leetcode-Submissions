class Solution
{
public:
    bool isPalindrome(int x)
    {
        string X = to_string(x);
        string Xrev = X;
        reverse(Xrev.begin(), Xrev.end());
        return X == Xrev;
    }
};