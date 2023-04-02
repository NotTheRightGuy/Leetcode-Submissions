class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> solution;
        for(int spell : spells){
            long successRatio = ceil((double)success / (double)spell);
            vector<int>::iterator val = lower_bound(potions.begin(),potions.end(),successRatio);
            solution.push_back(potions.size()-(val-potions.begin()));
        }
        return solution;
    }
};