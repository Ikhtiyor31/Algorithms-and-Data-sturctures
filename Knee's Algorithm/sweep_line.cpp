int solve(vector<vector<int>>& intervals) {
    // klee's algorithm
        vector<pair<int, int>> vp;
        for(vector<int> p: intervals) {
            bool first = false;
            for(int x: p) {
                vp.emplace_back(x, first);
                first = true;
            }
        }

        sort(vp.begin(), vp.end());
        int cnt = 0;
        int result = 0;
        int prev = -1;
        int mx = 0;
        for(pair<int, int> p: vp) {
            //cout << p.first << " : " << p.second << "\n";
            if (!p.second && cnt == 0) {
                prev = p.first;
                result = 0;
                cnt++;
                continue;
            }
            
            if (!p.second) {
                result += p.first - prev;
                prev = p.first;
                cnt++;
                continue;
            }
            result += p.first - prev;
            prev = p.first;
            cnt--;
            mx = max(result+1, mx);
        }

        return mx;   
}
