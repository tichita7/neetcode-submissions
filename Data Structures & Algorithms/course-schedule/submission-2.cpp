class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& path ){
        vis[node] = true;
        path[node] = true;

        for(auto& it: adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, path)) return true;
            } else if (path[it]){
                return true;
            }
        }
        path[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        vector<bool> path(n, false);

        for(auto& e: prerequisites){
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u); //v se u
        }

        for(int i = 0; i<n; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, path)) return false;
            }
        }

        return true;
    }
};
