// Approach - 2 (Optimal)
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<int> component(n, 0);

        for(int i = 1;i < n;i++){
            if(nums[i] - nums[i-1] <= maxDiff)
                component[i] = component[i-1];
            else
                component[i] = component[i-1] + 1;
        }

        int q_size = queries.size();
        vector<bool> ans(q_size, false);

        for(int i = 0;i < q_size;i++){
            int u = queries[i][0];
            int v = queries[i][1];

            if(component[u] == component[v])
                ans[i] = true;
        }

        return ans;
    }
};



// Approach - 1 (Better) (Disjoint Set Union)

// class DisjointSetUnion{
// private:
//     vector<int> parent, size;
// public:
//     DisjointSetUnion(int n){
//         size.resize(n,0);
//         parent.resize(n);

//         for(int i = 0;i < n;i++){
//             parent[i] = i;
//         }
//     }
    
//     int findParent(int node){
//         if(parent[node] == node) return node;
//         else return parent[node] = findParent(parent[node]);
//     }

//     void unionBySize(int u, int v){
//         int parent_u = findParent(u);
//         int parent_v = findParent(v);

//         if(parent_u == parent_v) return;

//         if(size[parent_u] < size[parent_v]){
//             parent[parent_u] = parent_v;
//             size[parent_v] += size[parent_u];
//         }
//         else{
//             parent[parent_v] = parent_u;
//             size[parent_u] += size[parent_v];
//         }
//     }
// };

// class Solution {
// public:
//     vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

//         DisjointSetUnion DSU(n);

//         for(int i = 1;i < n;i++){
//             if(nums[i] - nums[i-1] <= maxDiff){
//                 DSU.unionBySize(i, i-1);
//             }
//         }

//         int q_size = queries.size();
//         vector<bool> ans(q_size, false);

//         for(int i = 0;i < q_size;i++){
//             int u = queries[i][0];
//             int v = queries[i][1];

//             if(DSU.findParent(u) == DSU.findParent(v))
//                 ans[i] = true;
//         }

//         return ans;
//     }
// };