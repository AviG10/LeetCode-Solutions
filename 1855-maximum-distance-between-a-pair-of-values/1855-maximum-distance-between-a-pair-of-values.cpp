class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, ans = INT_MIN;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]) ans = max(ans,j-i), j++;
            else i++; 
        }

        return (ans == INT_MIN || ans <= 0) ? 0 : ans;
    }
};