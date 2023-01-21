class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        vector<int> newArr;
        for (int i : arr)
        {
            newArr.push_back(i);
            if (i == 0)
            {
                newArr.push_back(0);
            }
        }
        newArr.resize(arr.size());
        arr = newArr;
    }
};