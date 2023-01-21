class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        bool result = false;
        
        unordered_map<int, int> record;
        
        for (int i = 0; i < arr.size(); i++)
        {
            
            if (record.count(2 * arr[i]) || (arr[i] % 2 == 0 && record.count(arr[i] / 2) ))
            {
                result = true;
                break;
            }
            else
            {
                record[arr[i]] = i;
            }
            
        }
        
        return result;
        
    }
};