class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int lowest = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            if(i % 10 == nums[i]){
                lowest = min(lowest, i);
            }
        }
        if(lowest == INT_MAX) return -1;
        else return lowest;
    }
};