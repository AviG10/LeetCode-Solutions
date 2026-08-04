class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int smallest = INT_MAX, largest = INT_MIN;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            smallest = min(smallest, nums[i]);
            largest = max(largest, nums[i]);
            mp[nums[i]]++;
        }

        vector<int> ans;
        for (int num = smallest; num <= largest; num++) {
            if (mp[num] == 0) {
                ans.push_back(num);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};