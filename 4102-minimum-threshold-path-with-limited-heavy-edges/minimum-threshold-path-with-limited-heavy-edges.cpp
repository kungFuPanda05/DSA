class Solution {
public:
    const int inf = INT_MAX-100;
    vector <vector <pair<int, int>>> graph;
    int src;
    int target;
    int n, k;
    bool f(int threshold){

        vector <int> dist(n+1, inf);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector <pair<int, int>>, greater <pair<int, int>>> pq;
        
        pq.push({0, src});
        int count = 0;
        while(!pq.empty()){
            pair<int, int> top = pq.top();
            pq.pop();
            int vertex = top.second;
            int dis = top.first;
            if(dist[vertex]<dis) continue;
            if(vertex==target) return true;
            
            for(auto childNode: graph[vertex]){ 
                int child = childNode.first;
                int wt = (childNode.second>threshold)?1:0;
                if(dist[vertex]+wt < dist[child] && (dist[vertex]+wt)<=k){
                    dist[child] = dist[vertex]+wt;
                    pq.push({dist[child], child});
                }
            }
        }
        return false;
    }

    int minimumThreshold(int N, vector<vector<int>>& edges, int source, int Target, int K) {
        src = source;
        target = Target;
        n = N;
        k = K;
        graph = vector <vector <pair<int, int>>> (n);
        int ma = -1;
        for(auto val: edges){
            int u = val[0];
            int v = val[1];
            int wt = val[2];
            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
            ma = max(ma, wt);
        }
        int l=0;
        int h=ma+1;
        while(h-l>1){
            int mid = l+(h-l)/2;
            if(f(mid)) h=mid;
            else l=mid;
        }
        if(f(l)) return l;
        if(f(h)) return h;
        return -1;
    }
};