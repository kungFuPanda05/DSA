class Solution {
public:
    vector <long long> graph[100001];
    long long h(int vertex){
        long long ans = 0;
        for(auto child: graph[vertex]){
            ans = max(ans, h(child));
        }
        return ans+1;
    }
    long long height;
    long long finalAns;
    vector <int> arr;
    void dfs(long long vertex, long long d){

        finalAns += arr[vertex]*(height - d + 1);
        for(auto child: graph[vertex]){
            dfs(child, d+1);
        }
    }

    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        for(int i=0; i<parent.size(); i++){
            if(parent[i]>=0) graph[parent[i]].push_back(i);
        }
        height = h(0);
        arr = nums;
        finalAns = 0;
        dfs(0, 1);
        return finalAns;
    }
};