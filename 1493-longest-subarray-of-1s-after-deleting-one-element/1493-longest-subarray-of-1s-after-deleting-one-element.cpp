class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int cntOne = 0, cntZero = 0;
        int ans = 0;

        while(j < n){
            if(nums[j] == 1)
                cntOne++;
            else 
                cntZero++;

            while(cntZero > 1){
                if(nums[i] == 0)
                    cntZero--;
                i++;
            }
            
            ans = max(ans, j - i);
            j++;
        }

        return ans;
    }
};