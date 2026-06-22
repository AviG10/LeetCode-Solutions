class Solution {
private:
    int getSum(int num){
        string numStr = to_string(num);
        int n = numStr.length();
        int sum = 0;

        for(int i = 0;i < n;i++){
            sum += numStr[i] - '0';
        }

        return sum;
    }
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;

        for(int i = 0;i < n;i++){
            int sum = getSum(nums[i]);
            mini = min(mini,sum);
        }

        return mini;
    }
};