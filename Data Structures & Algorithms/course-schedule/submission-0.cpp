class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //topo sort -- BFS
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> vis(n, -1);
        vector<int> indeg(n, 0);

        queue<int> q;

        for(auto& e: prerequisites){
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u); //v se u
            indeg[u]++; 
        }

        int cnt = 0;

        for(int i = 0; i<n; i++){
            if(indeg[i] == 0){
                q.push(i);
                cnt++;
            }
        }

        if(cnt == 0) return false; //there is a cycle

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto& a: adj[node]){
                indeg[a]--;

                if(indeg[a] == 0){
                    q.push(a);
                    cnt++;
                }
            }
        }

        return (cnt == n) ? true : false;

    }
};
