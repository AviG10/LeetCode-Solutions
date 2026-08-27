class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = 0, curOnes = 0, maxOnes = 0;

        for(int i = 0; i < n; i++)
            totalOnes += nums[i];
        
        int i = 0, j = 0;

        while( j < 2 * n){
            curOnes += nums[j % n];

            if(j - i + 1 > totalOnes){
                curOnes -= nums[i % n];
                i++;
            }

            maxOnes = max(maxOnes, curOnes);
            j++;
        }   

        return totalOnes - maxOnes;
    }
};