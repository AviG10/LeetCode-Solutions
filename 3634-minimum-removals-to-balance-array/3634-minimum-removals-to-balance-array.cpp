// (n - maximum length Balanced Subarray)
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int n = nums.size();
        int i = 0, j = 0;
        int ans = 1;

        while(j < n){
            // If we increase j more, number will be bigger than current, so, No Point of increasing j, without increasing i
            while( (long long) nums[j] > (long long)nums[i]*k ) i++; 
            ans = max(ans,j-i+1);
            j++;
        }

        return (n-ans);
    }
};