class Solution {
private:
    void buildAdjacencyList(unordered_map<int, vector<pair<int,int>>> &adj, vector<vector<int>> &roads){
        
        for(auto it: roads){
            int u = it[0];
            int v = it[1];
            int dist = it[2];

            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }
    }

    void dfs(int node, unordered_map<int, vector<pair<int,int>>> &adj, vector<bool> &vis, int &minDist){
        if(vis[node] == true)
            return;
        
        vis[node] = true;

        for(auto &it : adj[node]){
            int v = it.first;
            int dist = it.second;

            minDist = min(minDist, dist);

            dfs(v, adj, vis, minDist);
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        unordered_map<int, vector<pair<int,int>>> adj;
        
        buildAdjacencyList(adj, roads);

        vector<bool> vis(n+1, false);
        int minDist = INT_MAX;
        
        dfs(1, adj, vis, minDist);

        return minDist;
    }
};