class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool allZero = true;
        int resultXor = 0;

        for (int i = 0; i < n; i++) {
            resultXor = resultXor ^ nums[i];

            if (nums[i] != 0)
                allZero = false;
        }

        return allZero ? 0 : resultXor ? n : n - 1;
    }
};