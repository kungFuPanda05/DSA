class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char target) {
        int idx = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        if(idx==arr.size()) return arr[0];
        return arr[idx];
    }
};