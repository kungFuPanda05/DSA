class Solution {
public:
    int vis[201];
    vector <vector <int>> graph;

    void dfs(int vertex){
        
        if(vis[vertex]) return;

        vis[vertex] = 1;
        for( auto child: graph[vertex]){
            dfs(child);
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        graph = vector <vector <int>> (n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                count++;
                dfs(i);
            }
        }
        return count;
    }
};