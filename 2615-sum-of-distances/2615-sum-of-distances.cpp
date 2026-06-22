class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n,0);

        unordered_map<int,long long> indexCntLeft;
        unordered_map<int,long long> indexSumLeft;

        // Left to Right
        for(int i = 0;i < n;i++){
            long long freq = indexCntLeft[nums[i]];
            long long sum = indexSumLeft[nums[i]];

            ans[i] += (freq*i - sum);

            indexCntLeft[nums[i]]++;
            indexSumLeft[nums[i]] += i;
        }

        unordered_map<int,int> indexCntRight;
        unordered_map<int,long long> indexSumRight;

        // Right to Left
        for(int i = n-1;i >= 0;i--){
            long long freq = indexCntRight[nums[i]];
            long long sum = indexSumRight[nums[i]];

            ans[i] += (long long)(sum - freq*i);

            indexCntRight[nums[i]]++;
            indexSumRight[nums[i]] += i;
        }

        return ans;
    }
};