class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        if (arr.size() <= 1)
            return false;
        if (arr.size() >= 2 && arr[0] > arr[1])
            return false;
        int peak{0};
        for (int i = 1; i < arr.size(); i++)
        {
            if (!peak)
            {
                if (arr[i] > arr[i - 1])
                    continue;
                else if (arr[i] < arr[i - 1] && !peak)
                    peak++;
                else
                    return false;
            }
            else
            {
                if (arr[i] < arr[i - 1])
                    continue;
                else if (arr[i] > arr[i - 1] && !peak)
                    peak++;
                else
                    return false;
            }
        }
        if(!peak) return false;
        return true;
    }
};