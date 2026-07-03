// Binary Search on Answer + Dijkstra's Algorithm
class Solution {
private:
    typedef pair<long long, int> P;

    void buildAdjacencyList(unordered_map<int, vector<vector<int>>>& adj,
                            vector<vector<int>>& edges, vector<bool>& online,
                            int& minCost, int& maxCost) {
        
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int edgeCost = edge[2];

            if(online[u] && online[v]){
                adj[u].push_back({v, edgeCost});
                minCost = min(minCost, edgeCost);
                maxCost = max(maxCost, edgeCost);
            }
        }
    }

    bool check(int mid, int &n, long long &k, unordered_map<int, vector<vector<int>>> &adj){
        
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<long long> res(n, LLONG_MAX);

        res[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            long long totalCost = it.first;
            int node = it.second;

            if(totalCost > k) 
                return false;
            
            if(node == n-1)
                return true;
            
            if(res[node] < totalCost)
                continue;
            
            for(auto &it : adj[node]){
                int v = it[0];
                int edgeCost = it[1];

                if(edgeCost >= mid){
                    if(totalCost + edgeCost < res[v]){
                        res[v] = totalCost + edgeCost;
                        pq.push({totalCost + edgeCost, v});
                    }
                }
            }
        }

        return false;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        unordered_map<int, vector<vector<int>>> adj;
        int minCost = INT_MAX;
        int maxCost = INT_MIN;
        int n = online.size();

        buildAdjacencyList(adj, edges, online, minCost, maxCost);

        int low = minCost;
        int high = maxCost;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(check(mid, n, k, adj)){
                low = mid + 1;
                ans = mid;
            }
            else 
                high = mid - 1;
        }

        return ans;
    }
};