class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int count = 0, small = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                count++;
            } else if (nums[i] < target) {
                small++;
            }
        }

        for (int i = small; i < small + count; i++) {
            ans.push_back(i);
        }
        return ans;
    }
};