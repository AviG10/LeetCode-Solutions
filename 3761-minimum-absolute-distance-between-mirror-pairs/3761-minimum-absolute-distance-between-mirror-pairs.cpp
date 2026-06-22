class Solution {
private:
    int getReverse(int num){
        int rev = 0;

        while(num > 0){
            int rem = num%10;
            rev = rev*10 + rem;
            num /= 10;
        }

        return rev;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> reverseMp;
        int ans = INT_MAX;

        for(int i = 0;i < n;i++){
            if(reverseMp.find(nums[i]) != reverseMp.end()){
                ans = min(ans,i-reverseMp[nums[i]]);
            }

            reverseMp[getReverse(nums[i])] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};