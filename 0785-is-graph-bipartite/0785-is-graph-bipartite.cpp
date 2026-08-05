class Solution {
public:

    bool dfs(vector<vector<int>>& graph, int node, vector<int>& vis){
        int m = graph[node].size();
        for(int j=0; j<m; j++){
            if(vis[graph[node][j]] == -1){
                vis[graph[node][j]] = 1 - vis[node];
                if(!dfs(graph, graph[node][j], vis)){
                    return false;
                }
            }
            else if(vis[graph[node][j]] == vis[node]){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for(int i=0; i<n; i++){
            if(vis[i] == -1){
                vis[i] = 0;
                if(!dfs(graph, i, vis)){
                    return false;
                }
            }
        }
        return true;
    }
};