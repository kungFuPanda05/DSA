#include <map>
#include <tuple>

class Solution {
public:
    // Key: (prev1, prev2, i, tight, leading)
    map<tuple<char,char,int,bool,bool>, pair<long long,long long>> memo;

    pair<long long,long long> f(char prev1, char prev2, int i,
                                 bool tight, bool leading, string &s) {
        auto key = make_tuple(prev1, prev2, i, tight, leading);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        if (i == (int)s.size()) return {0, 1};

        pair<long long,long long> ans = {0, 0};
        for (char ch = '0'; ch <= '9'; ch++) {
            if (tight && ch > s[i]) continue;

            long long contribution = 0;
            if (!leading) {
                if (prev2 > prev1 && prev2 > ch) contribution++;
                if (prev2 < prev1 && prev2 < ch) contribution++;
            }

            auto [subSum, subCount] = f(prev2, ch, i + 1,
                                         tight && ch == s[i],
                                         prev2 == '0' && leading, s);

            ans.first  += subSum + contribution * subCount;
            ans.second += subCount;
        }

        return memo[key] = ans;
    }

    long long totalWaviness(long long num1, long long num2) {
        string s1 = to_string(num1 - 1);
        string s2 = to_string(num2);

        memo.clear();
        long long r2 = f('0', '0', 0, true, true, s2).first;
        memo.clear();
        long long r1 = f('0', '0', 0, true, true, s1).first;

        return r2 - r1;
    }
};