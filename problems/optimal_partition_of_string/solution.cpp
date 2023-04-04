class Solution {
public:
    int partitionString(string s) {
        map<char,int> smap;
        int count = 1;
        for(char i : s){
            if(smap[i] != 0){
                count++;
                smap.clear();
            }
            smap[i]++;
        }
        return count;
    }
};