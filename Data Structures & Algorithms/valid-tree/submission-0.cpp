class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, int parent){
        vis[node] = true;

        for(auto& it: adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, node)) return true;
            } else if (it != parent){
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        //tree is an undirected graph without cycles
        //all nodes as one single component
        //two nodes having exactly one path

        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        for(auto& e: edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt = 0;

        //detect cycle
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, -1)) return false;
                cnt++;
                if(cnt > 1) return false;
            }
        }

        return true;
    }
};
