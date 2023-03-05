// Jump Game 4 Solution by NotTheRightGuy
// Time Complexity is O(n) {BFS is of O(n)} and Space Complexity is O(n) {Initialising linear map and array only}
class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, vector<int>> indicesOfValue; // Creating a Map to store all position for every value
        for (int i = 0; i < n; i++)
        {
            indicesOfValue[arr[i]].push_back(i);
        }
        vector<bool> visited(n); // Creating a visited array for BFS
        visited[0] = true;       // Starting From Zero hence the first node is visited
        queue<int> q;            // Making a queue for BFS
        q.push(0);
        int step = 0; // Initiliasing step counter

        while (!q.empty())
        {
            for (int size = q.size(); size > 0; size--)
            {
                int current = q.front();
                q.pop();
                if (current == n - 1)                            // Reached Last Index
                    return step;                                 // Returning the Current Count
                vector<int> next = indicesOfValue[arr[current]]; // Initilasing a new array which contain all places we can go by jumping at the same value
                next.push_back(current + 1);                     // Adding Next index
                next.push_back(current - 1);                     // Adding Last Index

                for (int j : next)
                {                                       // Iterating the next possible value index
                    if (j >= 0 && j < n && !visited[j]) // If it's positive, less than size of array and hasn't yet been visited
                    {
                        visited[j] = true; // Set the node to visited
                        q.push(j);         // Add the node to queue for next iteration
                    }
                }
                indicesOfValue[arr[current]].clear(); // To avoid checking the same value for later iteration
            }
            step++;
        }
        return 0;
    }
};