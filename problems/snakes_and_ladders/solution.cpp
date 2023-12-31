class Solution {
public:
     int snakesAndLadders(vector<vector<int>>& b) {
        int n = b.size ();
        vector<vector<int>> v (n*n+1, vector<int> (2));
        int x = 1, r = n-1, c = 0, add = 1;
        while (x <= n*n) {
            v[x][0] = r;
            v[x][1] = c;          
            if      (add ==  1 && c < n - 1) c++;
            else if (add == -1 && c > 0)     c--;
            else if (add == 1) add = -1, r--;
            else               add =  1, r--;
            x++;
        }
        
        set<pair<int, int>> m; 
        m.insert ({0, 1});
        while (true) {
            auto p = *m.begin ();
            if (p.first > n*n) return -1;
            int i = v[p.second][0];
            int j = v[p.second][1];
            if (b[i][j] != -1) p.second = b[i][j];
            if (p.second == n*n) return p.first;
            m.erase (m.begin ());
            for (int i = 1; i <= 6; ++i) m.insert ({p.first+1, min (p.second+i, n*n)});
        }
    }
};