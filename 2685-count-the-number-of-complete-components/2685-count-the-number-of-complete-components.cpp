class DisjointSetUnion{
public:
    vector<int> parent, size;
    DisjointSetUnion(int n){
        size.resize(n,1);
        parent.resize(n);

        for(int i = 0;i < n;i++){
            parent[i] = i;
        }
    }
    
    int findParent(int node){
        if(parent[node] == node) return node;
        else return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int parent_u = findParent(u);
        int parent_v = findParent(v);

        if(parent_u == parent_v) return;

        if(size[parent_u] < size[parent_v]){
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
        else{
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSetUnion DSU(n);
        
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            DSU.unionBySize(u, v);
        }

        unordered_map<int, int> mp;

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            int root = DSU.findParent(u);
            mp[root]++;
        }

        int result = 0;
        for(int i = 0;i < n;i++){
            if(DSU.findParent(i) == i){
                int v = DSU.size[i];
                int e = mp[i];

                if((v*(v-1))/2 == e)
                    result++;
            }
        }

        return result;
    }
};