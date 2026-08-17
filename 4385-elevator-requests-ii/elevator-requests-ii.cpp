class Solution {
public:
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        vector<int> a = requests;
        sort(a.begin(), a.end());
        int m = a.size();
        const long long INF = LLONG_MAX / 4;

        // cur[i] = {cost when elevator sits at a[i] (left end), cost when at a[i+len-1] (right end)}
        vector<array<long long,2>> cur(m, {INF, INF}), nxt(m);

        int r = lower_bound(a.begin(), a.end(), start) - a.begin();
        if (r < m && a[r] == start) {
            cur[r] = {0, 0};                       // start itself is fulfilled at time 0
        } else {
            int l = r - 1;                         // nothing requested strictly between a[l] and a[r]
            if (l >= 0) { long long c = (long long)(start - a[l]) * m; cur[l] = {c, c}; }
            if (r <  m) { long long c = (long long)(a[r] - start) * m; cur[r] = {c, c}; }
        }

        for (int len = 1; len < m; ++len) {
            for (int i = 0; i < m; ++i) nxt[i] = {INF, INF};
            long long rem = m - len;               // requests still waiting during this move
            for (int i = 0; i + len - 1 < m; ++i) {
                int j = i + len - 1;
                for (int side = 0; side < 2; ++side) {
                    long long v = cur[i][side];
                    if (v >= INF) continue;
                    int pos = side == 0 ? a[i] : a[j];
                    if (i > 0)     nxt[i-1][0] = min(nxt[i-1][0], v + (long long)(pos - a[i-1]) * rem);
                    if (j + 1 < m) nxt[i][1]   = min(nxt[i][1],   v + (long long)(a[j+1] - pos) * rem);
                }
            }
            swap(cur, nxt);
        }
        return min(cur[0][0], cur[0][1]);
    }
};