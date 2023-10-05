class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int count =0;
        int start =0;
        int end =n-1;
        int aliceCC = capacityA;
        int bobCC = capacityB;
        while(start<=end){
           
            if(start==end){
               if(aliceCC>=bobCC){
                    if(aliceCC>=plants[start]){
                        aliceCC-=plants[start];
                    }
                    else{
                        aliceCC=capacityA;
                         count+=1;
                    }
               }
               else{
                   if(bobCC>=plants[end]){
                          bobCC-=plants[end];
                    }
                    else{
                           bobCC=capacityB;
                           count+=1;
                     }
               }
              break;
            }
            if(aliceCC>=plants[start]){
                 aliceCC-=plants[start];
            }
            else{
                aliceCC=capacityA;
                aliceCC-=plants[start];
                count+=1;
            }
            if(bobCC>=plants[end]){
                 bobCC-=plants[end];
            }
            else{
                bobCC=capacityB;
                bobCC-=plants[end];
                count+=1;
            }


            start++;
            end--;
        }
    return count;   
    }
};