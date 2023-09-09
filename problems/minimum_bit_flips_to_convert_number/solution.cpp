class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp = goal ^ start;
        int ans = 0;
        while(temp > 0){
            temp = temp & (temp-1);
            ans++;
        }
        return ans;
    }
};