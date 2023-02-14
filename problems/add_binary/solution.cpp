class Solution {
public:
    string addBinary(string a, string b)
{
    string result = "";
    int temp = 0;
    int a_n = a.size() - 1;
    int b_n = b.size() - 1;
    while (a_n >= 0 || b_n >= 0 || temp == 1)
    {
        temp += (a_n >= 0) ? a[a_n] - '0' : 0;
        temp += (b_n >= 0) ? b[b_n] - '0' : 0;
        result.push_back(char(temp % 2 + '0'));
        temp /= 2;
        a_n--;
        b_n--;
    }
    reverse(result.begin(), result.end());
    return result;
}
};