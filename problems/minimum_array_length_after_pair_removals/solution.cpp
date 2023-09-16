class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        int left,right;
        int removed = 0;
        left = 0;
        if(n % 2 != 0){
            right = (n/2)+1;
        }
        else{
            right = n/2;
        }
        while(right < n){
            if(nums[left] < nums[right]){
                removed+=2;
            }
            right++;
            left++;
        }
        return n - removed;
    }
};