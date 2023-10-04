
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        unordered_map<int, int> changeCount;
        for (int i : bills)
        {
            if (i == 5)
            {
                changeCount[5]++;
            }
            else if (i == 10)
            {
                if (changeCount[5])
                {
                    changeCount[5]--;
                    changeCount[10]++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (changeCount[10] && changeCount[5])
                {
                    changeCount[10]--;
                    changeCount[5]--;
                    changeCount[20]++;
                }
                else if (changeCount[5] >= 3)
                {
                    changeCount[5] -= 3;
                    changeCount[20]++;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};