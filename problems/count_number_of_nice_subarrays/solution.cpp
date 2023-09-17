class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        map<int, int> prefixOdd;
        prefixOdd[0] = 1;
        int soFarOdd = 0;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 != 0)
            {
                soFarOdd++;
            }
            int remaining = soFarOdd - k;
            cnt += prefixOdd[remaining];
            prefixOdd[soFarOdd]++;
        }
        return cnt;
    }
};