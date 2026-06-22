class Solution {
private:
    bool checkBalance(vector<int>& nums){
        int common = 0;

        for(int i = 0;i < 26;i++){
            if(nums[i] == 0) continue;
            
            if(common == 0) common = nums[i];
            else if(common != nums[i]) return false;
        }

        return true;
    }
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;

        for(int i = 0;i < n;i++){
            vector<int> nums(26,0);
            
            for(int j = i;j < n;j++){
                nums[s[j]-'a']++;
 
                if(checkBalance(nums)){
                    ans = max(ans,j-i+1);
                } 
            }
        }

        return ans;
    }
};