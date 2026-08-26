class Solution {
private:
    int numberOfSubarraysLessThanK(vector<int> &nums, int k){
        int n = nums.size();
        int cntOdd = 0, ans = 0;
        int i = 0, j = 0;

        while(j < n){
            if(nums[j] % 2 == 1)
                cntOdd++;

            while(cntOdd > k){
                if(nums[i] % 2 == 1)
                    cntOdd--;
                
                i++;
            }
            
            ans += (j-i+1);
            j++;
        }

        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numberOfSubarraysLessThanK(nums, k) - numberOfSubarraysLessThanK(nums, k-1);
    }
};