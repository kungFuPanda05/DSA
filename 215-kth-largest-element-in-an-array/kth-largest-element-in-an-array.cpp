class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int, vector <int>, greater <int>> pq;

        for(auto val: arr){
            pq.push(val);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};