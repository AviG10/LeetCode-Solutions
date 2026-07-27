class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max1 = INT_MIN, max2 = INT_MIN;

        for(int i = 0; i < n; i++){
            if(max1 < nums[i]){
                max2 = max1;
                max1 = nums[i];
            }
            else if(max2 < nums[i]){
                max2 = nums[i];
            }
        }

        return (max1 - 1) * (max2 - 1);
    }
};