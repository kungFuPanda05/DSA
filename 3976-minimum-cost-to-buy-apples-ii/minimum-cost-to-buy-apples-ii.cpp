class Solution {
public:
    using ll = long long;
    const ll INF = 4e18;

    void dijkstraRec(
        priority_queue<pair<ll, int>,
                       vector<pair<ll, int>>,
                       greater<pair<ll, int>>> &pq,
        vector<ll> &dist,
        vector<vector<pair<int, ll>>> &graph
    ) {
        if (pq.empty()) return;

        auto [dis, vertex] = pq.top();
        pq.pop();

        if (dis == dist[vertex]) {
            for (auto [child, wt] : graph[vertex]) {
                if (dist[vertex] + wt < dist[child]) {
                    dist[child] = dist[vertex] + wt;
                    pq.push({dist[child], child});
                }
            }
        }

        dijkstraRec(pq, dist, graph);
    }

    vector<ll> dijkstra(int src, vector<vector<pair<int, ll>>> &graph) {
        int n = graph.size();
        vector<ll> dist(n, INF);

        priority_queue<pair<ll, int>,
                       vector<pair<ll, int>>,
                       greater<pair<ll, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        dijkstraRec(pq, dist, graph);

        return dist;
    }

    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<pair<int, ll>>> graph1(n);
        vector<vector<pair<int, ll>>> graph2(n);

        for (auto &val : roads) {
            int u = val[0];
            int v = val[1];
            ll c = val[2];
            ll t = val[3];

            graph1[u].push_back({v, c});
            graph1[v].push_back({u, c});

            graph2[u].push_back({v, c * t});
            graph2[v].push_back({u, c * t});
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            vector<ll> dist1 = dijkstra(i, graph1);
            vector<ll> dist2 = dijkstra(i, graph2);

            ll best = prices[i];

            for (int j = 0; j < n; j++) {
                if (dist1[j] == INF || dist2[j] == INF) continue;

                best = min(best, (ll)prices[j] + dist1[j] + dist2[j]);
            }

            ans.push_back((int)best);
        }

        return ans;
    }
};