class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, sum = 0;
        int i = 0, j = n-1;

        while(i < k)
            sum += nums[i], i++;
        
        i--;
        ans = max(ans, sum);

        if(i == j) return ans;

        while(i >= 0 && j >= 0){
            sum -= nums[i];
            sum += nums[j];
            i--, j--;

            ans = max(ans, sum);
        }
        
        return ans;
    }
};