class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int Nsize = arr.size();
        int countNumberofZeros = count(arr.begin(), arr.end(), 0);
        vector<int> newVector(arr.size() + countNumberofZeros);
        int indexOfNew{0}, indexOfOld{0};
        while (indexOfOld < arr.size())
        {
            newVector[indexOfNew] = arr[indexOfOld];
            if (arr[indexOfOld] == 0)
            {
                newVector[indexOfNew + 1] = 0;
                indexOfNew++;
            }
            indexOfNew++;
            indexOfOld++;
        }
        arr = newVector;
        arr.resize(Nsize);
    }
};