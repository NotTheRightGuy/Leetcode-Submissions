class Solution {
public:
    int countOdds(int low, int high) {
        int diff = high - low;
        if(!(diff%2) && !(high%2)) return diff/2;
        else if(!(diff%2)) return diff/2 + 1;
        else return (diff+1)/2;
    }
};