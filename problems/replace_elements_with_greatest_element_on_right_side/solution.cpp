class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int oldmax = -1;
        int len = arr.size();
        for (int i = len - 1; i >= 0; i--)
        {
            int newmax = max(oldmax, arr[i]);
            arr[i] = oldmax;
            oldmax = newmax;
        }
        return arr;
    }
};