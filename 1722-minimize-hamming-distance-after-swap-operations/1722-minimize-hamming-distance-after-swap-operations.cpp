class DisjointSetUnion{
private:
    vector<int> parent, size;
public:
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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DisjointSetUnion DSU(n);

        for(auto it: allowedSwaps){
            DSU.unionBySize(it[0],it[1]);
        }

        unordered_map<int,unordered_map<int,int>> mp;
        for(int i = 0;i < n;i++){
            int parent = DSU.findParent(i);
            mp[parent][source[i]]++;
        }

        int hammingDist = 0;
        for(int i = 0;i < n;i++){
            int parent = DSU.findParent(i);
            
            if(mp[parent][target[i]] > 0) mp[parent][target[i]]--;
            else hammingDist++;
        }

        return hammingDist;
    }
};