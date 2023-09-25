class Solution {
public:
    char findTheDifference(string s, string t) {
       int sv = 0;
       int tv = 0;

       for(auto i : s) sv+=i;
       for(auto i : t) tv += i;
       return char(tv-sv);
    }
};