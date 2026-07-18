class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minEle = *min_element(nums.begin(), nums.end());
        int maxEle = *max_element(nums.begin(), nums.end());
        return __gcd(minEle, maxEle);
    }
};