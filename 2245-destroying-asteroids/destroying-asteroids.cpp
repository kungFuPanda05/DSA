class Solution {
public:
    bool asteroidsDestroyed(int Mass, vector<int>& arr) {
        sort(arr.begin(), arr.end());

        long long mass = Mass;

        for (int asteroid : arr) {
            if (asteroid > mass) {
                return false;
            }
            mass += asteroid;
        }

        return true;
    }
};