class Solution {
public:
     int leastInterval(vector<char> tasks, int n)
    {
        map<char, int> mp;
        priority_queue<int> pq;
        for (auto i : tasks)
        {
            mp[i]++;
        }
        for (auto i : mp)
            pq.push(i.second);
        int time = 0;
        while (!pq.empty())
        {
            vector<int> remain;
            int cycle = n + 1;
            while (cycle && !pq.empty())
            {
                int maxF = pq.top();
                pq.pop();
                if (maxF > 1)
                    remain.push_back(maxF - 1);
                time++;
                cycle--;
            }

            for (int count : remain)
            {
                pq.push(count);
            }
            if (pq.empty())
                break;
            time += cycle;
        }
        return time;
    }
};