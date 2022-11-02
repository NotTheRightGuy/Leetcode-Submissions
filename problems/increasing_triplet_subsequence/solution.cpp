class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX;
        int mid = INT_MAX;
        for(auto x : nums){
            if(x > mid) return true;
            else if(x < mid && x > left) mid = x;
            else if(x < left) left = x;
        }
        return false;
    }
};