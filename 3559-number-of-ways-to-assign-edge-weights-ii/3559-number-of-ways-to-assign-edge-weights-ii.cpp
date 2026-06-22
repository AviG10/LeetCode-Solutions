class Solution {
private:
    int MOD = 1e9 + 7;
    
    void buildGraph(unordered_map<int,vector<int>> &adj, vector<vector<int>>& edges){    
        
        for(auto &edge: edges){
            int u = edge[0] - 1;
            int v = edge[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void dfs(int root, int parent, unordered_map<int,vector<int>> &adj, vector<int> &depth, vector<vector<int>> &ancestorTable){
        ancestorTable[root][0] = parent;

        for(auto &child: adj[root]){
            if(child == parent) continue;
            
            depth[child] = depth[root] + 1;

            dfs(child, root, adj, depth, ancestorTable);
        }
    }

    void buildAncestorTable(vector<vector<int>> &ancestorTable, int &cols, int &n){
        for(int j = 1;j < cols;j++){
            for(int node = 0; node < n;node++){
                if(ancestorTable[node][j-1] != -1)
                    ancestorTable[node][j] = ancestorTable[ancestorTable[node][j-1]][j-1];
            }
        }
    }

    int findLCA(int u, int v, int &cols, vector<int> &depth, vector<vector<int>> &ancestorTable){
        if(depth[u] < depth[v]) 
            swap(u, v);

        int k = depth[u] - depth[v];

        for(int j = 0;j < cols;j++){
            if(k & (1 << j)){
                u = ancestorTable[u][j];
            }
        }

        if(u == v) 
            return v;

        for(int j = cols - 1;j >= 0;j--){
            if(ancestorTable[u][j] == -1) continue;

            if(ancestorTable[u][j] != ancestorTable[v][j]){
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0];
    }

    long long power(long long base, long long exponent){
        if(exponent == 0) 
            return 1;
        
        long long half = power(base, exponent / 2);

        long long result = (half * half) % MOD;

        if(exponent % 2 == 1)
            result = ( result * base ) % MOD;

        return result;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1; // No. of Nodes
        int rows = n;
        int cols = log2(n) + 1;

        unordered_map<int,vector<int>> adj;
        
        buildGraph(adj, edges); // Step - 1 : Building Graph

        vector<int> depth(n, 0);
        vector<vector<int>> ancestorTable(rows, vector<int>(cols, -1));

        dfs(0, -1, adj, depth, ancestorTable); // Step - 2 : Precomputing depths and 0th column of ancestorTable

        buildAncestorTable(ancestorTable, cols, n); // Step - 3 : Build ancestorTable for Binary Lifting

        vector<int> ans;
        
        // Step - 6 : Process Queries Given
        for(auto &query: queries){
            int u = query[0] - 1;
            int v = query[1] - 1;

            int lca = findLCA(u, v, cols, depth, ancestorTable); // Step - 4: Find LCA of (u, v)

            int d = depth[u] + depth[v] - 2 * depth[lca];

            if(d == 0) 
                ans.push_back(0);
            else 
                ans.push_back(power(2, d-1)); // Step - 5: Binary Exponentiation
        }

        return ans;
    }
};