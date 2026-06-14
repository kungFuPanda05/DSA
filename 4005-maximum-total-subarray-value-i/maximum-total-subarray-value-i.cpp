class Solution {
public:
    long long maxTotalValue(vector<int>& arr, int k) {
        int ma = *max_element(arr.begin(), arr.end());
        int mi = *min_element(arr.begin(), arr.end());

        return (ma-mi)*1ll*k;
    }
};