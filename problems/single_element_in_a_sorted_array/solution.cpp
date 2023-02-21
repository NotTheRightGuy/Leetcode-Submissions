class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int currXor = 0;
        for(int i : nums){
            currXor ^= i;
        }
        return currXor;
    }
};