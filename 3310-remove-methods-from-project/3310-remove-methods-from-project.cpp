class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        
        for(auto &edge : invocations){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<int> suspicious(n,0);
        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while(!q.empty()){
            int curNode = q.front();
            q.pop();

            for(int &node : adj[curNode]){
                indegree[node]--;

                if(suspicious[node] == false){
                    suspicious[node] = true;
                    q.push(node);
                }
            }
        }

        vector<int> ans;
        for(int i = 0;i < n;i++){
            if(suspicious[i] && indegree[i] > 0){
                ans.clear();
                
                for(int i = 0;i < n;i++)
                    ans.push_back(i);
                
                break;
            }
            
            if(suspicious[i] == false){
                ans.push_back(i);
            }
        }

        return ans;
    }
};