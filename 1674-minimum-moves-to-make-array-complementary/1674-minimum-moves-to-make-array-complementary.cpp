class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2*limit+2,0);

        for(int i = 0;i < n/2;i++){
            int a = nums[i];
            int b = nums[n-1-i];

            // Moves = 2
            diff[2] += 2;
            diff[2*limit+1] -= 2;

            // Moves = 1
            int minVal = min(a,b) + 1;
            int maxVal = max(a,b) + limit;
            diff[minVal] += (-1);
            diff[maxVal+1] -= (-1);

            // Moves = 0
            diff[a+b] += (-1);
            diff[a+b+1] -= (-1);
        }

        int ans = INT_MAX;
        for(int sum = 2;sum <= 2*limit;sum++){
            diff[sum] += diff[sum-1];
            ans = min(ans,diff[sum]);
        }

        return ans;
    }
};