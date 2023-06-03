
class Solution
{
public:
        string frequencySort(string s)
    {
        unordered_map<char, int> mx;

        for (auto i : s)
            mx[i]++;

        vector<pair<int, char>> vx;

        for (auto i = mx.begin(); i != mx.end(); i++)
            vx.push_back(make_pair(i->second, i->first));

        sort(vx.rbegin(), vx.rend());

        s.clear();

        for (int i = 0; i < vx.size(); i++)
        {
            int k = vx[i].first;
            while (k--)
                s += vx[i].second;
        }

        return s;
    }
};
