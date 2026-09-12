class Solution {
public:
    vector<vector<long long>> arr;
    int n;

    vector<int> nextIdx;

    struct State {
        long long score = -1;
        vector<int> ids;
    };

    vector<vector<State>> dp;

    State f(int i, int count) {

        if (i == n || count == 0) {
            return {0, {}};
        }

        if (dp[i][count].score != -1) {
            return dp[i][count];
        }

        State skip = f(i + 1, count);

        State take = f(nextIdx[i], count - 1);

        take.score += arr[i][2];

        int originalIndex = arr[i][3];

        auto it = lower_bound(
            take.ids.begin(),
            take.ids.end(),
            originalIndex
        );

        take.ids.insert(it, originalIndex);

        if (skip.score > take.score) {
            return dp[i][count] = skip;
        }

        if (take.score > skip.score) {
            return dp[i][count] = take;
        }

        if (skip.ids < take.ids) {
            return dp[i][count] = skip;
        }

        return dp[i][count] = take;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        arr.resize(n);

        for (int i = 0; i < n; i++) {
            arr[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(arr.begin(), arr.end());

        vector<long long> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = arr[i][0];
        }

        nextIdx.resize(n);

        for (int i = 0; i < n; i++) {
            nextIdx[i] = upper_bound(
                starts.begin(),
                starts.end(),
                arr[i][1]
            ) - starts.begin();
        }

        dp.resize(
            n,
            vector<State>(5)
        );

        return f(0, 4).ids;
    }
};