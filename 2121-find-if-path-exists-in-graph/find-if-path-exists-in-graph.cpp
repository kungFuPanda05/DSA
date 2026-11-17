class Solution {
public:

    vector <vector <int>> graph;
    int vis[500001];
    int dest;

    bool f(int vertex){
        if(vertex==dest) return true;
        if(vis[vertex]) return false;
        vis[vertex] = true;
        bool ans = false;
        for(auto child: graph[vertex]){
            ans = ans || f(child);
        }
        return ans;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        dest = destination;
        graph = vector <vector <int>> (n+1);
        for(auto val: edges){
            graph[val[0]].push_back(val[1]);
            graph[val[1]].push_back(val[0]);
        }
        return f(source);
    }
};