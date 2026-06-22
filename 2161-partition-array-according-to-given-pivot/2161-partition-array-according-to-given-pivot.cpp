class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n);
        int low = 0, equal = 0;

        for(int i = 0;i < n;i++){
            if(nums[i] < pivot) low++;
            if(nums[i] == pivot) equal++;
        }

        int high = low + equal;
        equal = low;
        low = 0;

        for(int i = 0;i < n;i++){
            if(nums[i] < pivot) res[low++] = nums[i];
            else if(nums[i] == pivot) res[equal++] = nums[i];
            else res[high++] = nums[i]; 
        } 

        return res;
    }
};