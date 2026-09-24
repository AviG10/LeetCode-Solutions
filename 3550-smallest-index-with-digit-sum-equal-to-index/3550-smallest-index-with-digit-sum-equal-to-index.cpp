class Solution {
private:
    int getSum(int n){
        int sum = 0;

        while(n > 0){
            int rem = n % 10;
            sum += rem;
            n /= 10;
        }

        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(getSum(nums[i]) == i){
                return i;
            }
        }

        return -1;
    }   
};