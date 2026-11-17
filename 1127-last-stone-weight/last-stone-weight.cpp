class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
        priority_queue<int> pq;
        for(auto val: arr) pq.push(val);

        while(!pq.empty()){
            if(pq.size()==1) return pq.top();
            int t1 = pq.top();
            pq.pop();
            int t2 = pq.top();
            pq.pop();
            int diff = abs(t1-t2);
            if(diff) pq.push(diff);
        }
        return 0;
    }
};