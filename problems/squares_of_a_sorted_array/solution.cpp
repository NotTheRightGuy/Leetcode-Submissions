class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> toReturn;
        for (int i : nums)
        {
            toReturn.push_back(i * i);
        }
        sort(toReturn.begin(),toReturn.end());
        return toReturn;
    }
};
