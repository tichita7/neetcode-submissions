class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
        vis[node] = true;

        for(auto& it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        int cnt = 0;

        for(auto& e: edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adj, vis);
                
            }
        }
        return cnt;
    }
};
