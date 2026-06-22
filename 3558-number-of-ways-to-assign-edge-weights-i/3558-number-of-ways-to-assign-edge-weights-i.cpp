class Solution {
private:
    int MOD = 1e9 + 7;

    long long power(long long base, long long exponent) {
        if (exponent == 0)
            return 1;

        long long half = power(base, exponent / 2);

        long long result = (half * half) % MOD;

        if (exponent % 2 == 1)
            result = (result * base) % MOD;

        return result;
    }

    int getDepth(unordered_map<int, vector<int>>& adj, int node, int parent) {
        int depth = 0;

        for (auto& child : adj[node]) {
            if (child == parent)
                continue;
            depth = max(depth, getDepth(adj, child, node) + 1);
        }

        return depth;
    }

    void buildGraph(unordered_map<int, vector<int>>& adj,
                    vector<vector<int>>& edges) {

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        buildGraph(adj, edges);

        int depth = getDepth(adj, 1, -1);

        return power(2, depth - 1);
    }
};