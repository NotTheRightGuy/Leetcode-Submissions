class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int numberOfOne = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == '1'){
                numberOfOne++;
            }
            else{
                res = min(numberOfOne,res+1);
            }
        }
        return res;
    }
};