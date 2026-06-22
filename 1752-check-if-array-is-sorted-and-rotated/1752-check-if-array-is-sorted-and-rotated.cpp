class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size() == 1) return true;

        int n = nums.size(), cnt = 0;

        for(int i = 1;i < n;i++){
            if(nums[i-1] > nums[i]) cnt++;
            if(cnt > 1) return false;
            if(cnt == 1 && nums[0] < nums[i]) return false;
        }

        return true;
    }
};