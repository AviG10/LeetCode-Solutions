class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = INT_MAX;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[low] <= nums[mid] && nums[mid] <= nums[high]){ // left and right both sorted
                ans = min(ans, nums[low]);
            }
            if(nums[low] <= nums[mid]){ // Left Sorted
                ans = min(ans,nums[low]);
                low = mid+1;  
            }
            else{ // Right Sorted
                high = mid-1;
                ans = min(ans,nums[mid]);
            }
        }

        return ans;
    }
};