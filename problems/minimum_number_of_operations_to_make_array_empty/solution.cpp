class Solution
{
public:
    pair<int, int> represent(int K)
    {
        int divBy3 = K / 3;
        while (divBy3 >= 0)
        {
            int rem = K - (divBy3 * 3);
            if (rem % 2 == 0)
            {
                return make_pair(divBy3, rem / 2);
            }
            divBy3--;
        }
        return make_pair(-1, -1);
    }

    int minOperations(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int x : nums)
        {
            freq[x]++;
        }
        int totalWays = 0;
        for (auto i : freq)
        {
            if (represent(i.second) != make_pair(-1, -1))
            {
                pair<int, int> p = represent(i.second);
                totalWays += p.first + p.second;
            }
            else
            {
                return -1;
            }
        }
        return totalWays;
    }
};