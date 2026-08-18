class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;

        if (k == 1) {
            unordered_map<int, int> mp;

            for (int i = 0; i < n; i++)
                mp[nums[i]]++;

            for (auto it : mp) {
                if (it.second == 1)
                    ans = max(ans, it.first);
            }
        } else if (k == n) {
            for (int i = 0; i < n; i++) {
                ans = max(ans, nums[i]);
            }
        } else {
            unordered_map<int, int> mp;

            for (int i = 0; i < n; i++)
                mp[nums[i]]++;

            if (mp[nums[0]] == 1)
                ans = max(ans, nums[0]);

            if (mp[nums[n - 1]] == 1)
                ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};