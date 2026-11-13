class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> m;
        for(auto val: arr){
            m[val] = 1;
        }

        int ans = 0;

        unordered_map<int, int> dp;

        for(auto val: m){
            if (m.find(val.first - 1) != m.end()) continue;
            int count = 0;
            int start = val.first;
            while (m.find(start) != m.end()){
                count++;
                start++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};