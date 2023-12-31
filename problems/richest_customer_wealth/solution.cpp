class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0,currWealth;
        for(int i = 0;i<accounts.size();i++){
            currWealth = 0;
            for(int j = 0;j<accounts[i].size();j++){
                currWealth += accounts[i][j];
            }
            maxWealth = max(maxWealth,currWealth);
        }
        return maxWealth;
    }
};