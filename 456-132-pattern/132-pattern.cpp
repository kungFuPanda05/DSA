class Solution {
public:
    bool find132pattern(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;

        stack<int> st;
        vector<int> left_g(n, -1);

        // left_g[i] = nearest previous greater element index
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                left_g[i] = st.top();
            }

            st.push(i);
        }

        vector<int> prefix(n);
        prefix[0] = arr[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = min(prefix[i - 1], arr[i]);
        }

        // arr[i] is the "2"
        for (int i = 2; i < n; i++) {
            int i2 = left_g[i]; // "3"

            if (i2 > 0 && prefix[i2 - 1] < arr[i] && arr[i] < arr[i2]) {
                return true;
            }
        }

        return false;
    }
};