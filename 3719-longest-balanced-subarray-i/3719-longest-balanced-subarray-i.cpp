class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0;i < n;i++){
            unordered_map<int,int> even,odd;
            
            for(int j = i;j < n;j++){
                if(nums[j]%2 == 1) odd[nums[j]]++;
                else even[nums[j]]++;

                if(even.size() == odd.size()) ans = max(ans,j-i+1);
            }
        }

        return ans;
    }
};