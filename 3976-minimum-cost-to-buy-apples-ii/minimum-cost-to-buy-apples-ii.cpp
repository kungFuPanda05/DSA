class Solution {
public:
    const long long inf = LONG_MAX-100;
    vector<long long> f(
        long long src,
        long long n,
        vector<vector<pair<long long, long long>>> &graph
    ) {
        const long long INF = 4e18;

        vector<long long> dist(n, INF);

        priority_queue<
            pair<long long, long long>,
            vector<pair<long long, long long>>,
            greater<pair<long long, long long>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [dis, vertex] = pq.top();
            pq.pop();

            if (dis > dist[vertex]) continue;

            for (auto child : graph[vertex]) {
                long long child_node = child.first;
                long long wt = child.second;

                if (dist[vertex] + wt < dist[child_node]) {
                    dist[child_node] = dist[vertex] + wt;
                    pq.push({dist[child_node], child_node});
                }
            }
        }

        return dist;
    }

    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector <vector <pair<long long, long long>>> graph1(n);
        vector <vector <pair<long long, long long>>> graph2(n);
        for(auto val: roads){
            long long u = val[0];
            long long v = val[1];
            long long c = val[2];
            long long t = val[3];
            graph1[u].push_back({v, c});
            graph1[v].push_back({u, c});

            graph2[u].push_back({v, c*t});
            graph2[v].push_back({u, c*t});
        }
        vector <int> ans;
        for(long long i=0; i<n; i++){
            long long temp = prices[i];
            vector <long long> dist1 = f(i, n, graph1);
            vector <long long> dist2 = f(i, n, graph2);
            for(long long j=0; j<n; j++){
                if(i==j) continue;
                long long cost = prices[j];
                long long ct1 = dist1[j];
                long long ct2 = dist2[j];
                if(ct1!=inf && ct2!=inf){
                    temp = min(temp, prices[j] + ct1 + ct2);
                }

            }
            ans.push_back(temp);
        }
        return ans;
    }
};