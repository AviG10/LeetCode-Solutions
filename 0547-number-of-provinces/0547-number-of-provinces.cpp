class Solution {
private:
    void dfs(int i, vector<int> adj[], vector<bool> &vis){
        vis[i] = true;

        for(int &it : adj[i]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n, false);
        int provinces = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                provinces++;
            }
        }
        
        return provinces;
    }
};