class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        
        if(n == 1) return cost[0];
        if(n == 2) return cost[0] + cost[1];

        sort(cost.begin(), cost.end(),greater<int>());
        
        int ans = 0;
        int i = 0;
        while(i + 1 < n){
            ans += cost[i];
            ans += cost[i+1];
            i += 3;
        }

        if(i < n) ans += cost[i];
        if(i+1 < n) ans += cost[i+1];

        return ans;
    }
};
