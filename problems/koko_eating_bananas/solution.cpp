#define all(x) x.begin(), x.end()

class Solution
{
public:
    long long solve(vector<int> &piles, int mid)
    {
        long long hours = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            int hoursPerPile = ceil(piles[i] / (double)mid);
            hours += hoursPerPile;
        }
        return hours;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int lower = 1;
        int upper = *max_element(all(piles));

        int ans = -1;
        while (lower <= upper)
        {
            int mid = lower + ((upper - lower) / 2);
            long long hoursToEatAll = solve(piles, mid);

            if (hoursToEatAll <= h)
            {
                ans = mid;
                upper = mid - 1;
            }
            else
                lower = mid + 1;
        }
        return ans;
    }
};
