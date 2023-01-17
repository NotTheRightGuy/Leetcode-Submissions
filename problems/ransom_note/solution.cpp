class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        map<char, int> magazineMap;
        for (auto i : magazine)
        {
            magazineMap[i]++;
        }
        for (auto i : ransomNote)
        {
            if (magazineMap.find(i) == magazineMap.end() || magazineMap[i] == 0)
            {
                return false;
            }
            magazineMap[i]--;
        }
        return true;
    }
};