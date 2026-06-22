class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;

        for(int i = 1;i <= 32;i++){
            ans = ans << 1; // Doing left shift to make space for inserting Least Significant Bit (LSB) / Right Most Bit
            ans = (ans | (n & 1)); // (n & 1) : Finding LSB / Right Most Bit
            n = n >> 1; // Right Shift to erase the LSB / Right Most Bit of n, as it's already being added to ans;
        }

        return ans;
    }
};