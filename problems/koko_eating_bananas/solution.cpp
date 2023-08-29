class Solution
{
public:
    bool ateAll(vector<int> piles, long long k, long long h)
    {
        long long timeElapsed = 0;
        for (int pile : piles)
        {

            timeElapsed += ceil(pile / (double)k);
        }
        return timeElapsed <= h;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int low = 1;
        int mid;
        int high = piles[n - 1];
        while (low <= high)
        {
            mid = (high + low) / 2;
            if (ateAll(piles, mid, h))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};