class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int day)
    {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int result = right;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (canShip(mid, weights, day))
            {
                result = min(mid, result);
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return result;
    }

    bool canShip(int capacity, vector<int> weights, int day)
    {
        int ships{1}, currCap{capacity};
        for (int i : weights)
        {
            if (currCap - i < 0)
            {
                ships++;
                currCap = capacity;
            }
            currCap -= i;
        }
        return true ? ships <= day : false;
    }
};