class DisjointSetUnion{
private:
    vector<int> parent, size;
public:
    DisjointSetUnion(int n){
        size.resize(n,0);
        parent.resize(n,0);
        
        for(int i = 0;i <= n-1;i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(node == parent[node]) return node;
        else return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int parent_u = findParent(u);
        int parent_v = findParent(v);

        if(parent_u == parent_v) return;
        else{
            if(size[parent_u] < size[parent_v]){
                parent[parent_u] = parent_v;
                size[parent_v] += size[parent_u];
            }
            else{
                parent[parent_v] = parent_u;
                size[parent_u] += size[parent_v];
            }
        }
    }
};


class Solution {
private:
    bool ifSpanningTreePossible(int &n, vector<vector<int>>& edges, int k, int minStrength){
        
        DisjointSetUnion DSU(n);
        vector<vector<int>> upgradeCandidates;

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            int s = edge[2];
            int m = edge[3];

            if(m == 1){
                if(s < minStrength) return false;
                else DSU.unionBySize(u,v);
            }
            else {
                if(s >= minStrength) DSU.unionBySize(u,v);
                else if(2*s >= minStrength) upgradeCandidates.push_back({u,v});
            }
        }

        for(auto &candidate: upgradeCandidates){
            int u = candidate[0];
            int v = candidate[1];

            if(DSU.findParent(u) != DSU.findParent(v)) {
                if(k <= 0) return false;
                else{
                    DSU.unionBySize(u,v);
                    k--;
                } 
            }
        }

        int root_val = DSU.findParent(0);

        for(int node = 1;node <= n-1;node++){
            if(DSU.findParent(node) != root_val) 
                return false;
        }

        return true;
    }   
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DisjointSetUnion DSU(n);
        int max_strength = INT_MIN;

        // Cycle Check Using DSU
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            int s = edge[2];
            int m = edge[3];

            if(m == 1){
                if(DSU.findParent(u) == DSU.findParent(v)) return -1;
                else DSU.unionBySize(u,v);

                max_strength = max(max_strength,s);
            }
            else max_strength = max(max_strength,2 * s);
        }

        // Binary Search on Answer - Finding Maximum of minimum 
        int low = 1, high = max_strength;
        int ans = -1;

        while(low <= high){
            int mid = low + ((high-low) >> 1);

            if(ifSpanningTreePossible(n,edges,k,mid)){
                ans = mid;
                low = mid+1;
            }   
            else high = mid-1;
        }

        return ans;
    }
};