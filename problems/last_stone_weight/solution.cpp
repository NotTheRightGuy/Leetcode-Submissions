class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int stone: stones){
            pq.push(stone);
        }
        while(pq.size()!=1){
           int maxT = pq.top();
           pq.pop();
           int maxS = pq.top();
           pq.pop();
           pq.push(maxT - maxS);
        }
        return pq.top();
    }
};