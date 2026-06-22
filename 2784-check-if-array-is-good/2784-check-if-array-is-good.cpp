class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return false;

        sort(nums.begin(), nums.end());

        int cnt = 1;
        for(int i = 0;i < n-1;i++){
            if(nums[i] != cnt) return false;
            cnt++;
        }
        
        return (nums[n-1] == nums[n-2]);
    }
};