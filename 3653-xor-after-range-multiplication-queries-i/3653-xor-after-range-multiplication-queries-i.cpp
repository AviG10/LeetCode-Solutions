class Solution {
private:
    int MOD = 1e9+7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        for(int i = 0;i < q;i++){
            int idx = queries[i][0];

            while(idx <= queries[i][1]){
                nums[idx] = (nums[idx] * (long long)queries[i][3]) % MOD;
                idx += queries[i][2];
            }
        }

        int ans = nums[0];
        for(int i = 1;i < n;i++){
            ans = ans ^ nums[i];
        }

        return ans;
    }
};