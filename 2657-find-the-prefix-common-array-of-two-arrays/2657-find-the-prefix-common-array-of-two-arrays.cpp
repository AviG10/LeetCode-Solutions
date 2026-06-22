class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int,int> mp;
        vector<int> ans(n,0);

        for(int i = 0;i < n;i++){
            int cnt = 0;

            if(mp[nums1[i]] > 0) cnt++;
            mp[nums1[i]]++;

            if(mp[nums2[i]] > 0) cnt++;
            mp[nums2[i]]++;

            if(i == 0) ans[i] = cnt;
            else ans[i] = ans[i-1] + cnt;
        }

        return ans;
    }
};