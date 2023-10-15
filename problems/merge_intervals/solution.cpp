
bool comp(vector<int> v1, vector<int> v2)
{
    return v1[0] < v2[0];
}

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> intervals)
    {
        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end(), comp);
        pair<int, int> currentInterval = {intervals[0][0], intervals[0][1]};
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= currentInterval.second)
            {
                currentInterval.second = max(currentInterval.second, intervals[i][1]);
            }
            else
            {
                answer.push_back({currentInterval.first, currentInterval.second});
                currentInterval.first = intervals[i][0];
                currentInterval.second = intervals[i][1];
            }
        }
        answer.push_back({currentInterval.first, currentInterval.second});
        return answer;
    }
};