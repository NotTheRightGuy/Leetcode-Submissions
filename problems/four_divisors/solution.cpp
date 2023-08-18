class Solution
{
public:
    int sumFourDivisors(vector<int> &nums)
    {
        int sum = 0;
        for (int num : nums)
        {
            int lastDiv = 0;
            int count = 0;
            for (int i = 2; i * i <= num; i++)
            {
                if (num % i == 0)
                {
                    count++;
                    lastDiv = i;
                }
            }
            if (count == 1 && lastDiv * lastDiv != num)
            {
                sum += 1 + num + lastDiv + (num / lastDiv);
            }
        }
        return sum;
    }
};