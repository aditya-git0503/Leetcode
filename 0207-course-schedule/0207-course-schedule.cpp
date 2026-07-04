class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& path, vector<int> adj[]) {
        vis[node] = 1;
        path[node] = 1;

        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode, vis, path, adj)){
                    return true;
                }
            }
            else if(path[adjNode]){
                return true;
            }
        }
        path[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int> vis(numCourses, 0);
        vector<int> path(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, path, adj)) {
                    return false;
                }
            }
        }
        return true;
    }
};