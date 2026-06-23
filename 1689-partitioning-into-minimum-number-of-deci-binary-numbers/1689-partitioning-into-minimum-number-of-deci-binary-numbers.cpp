class Solution {
public:
    int minPartitions(string num) {
        int n = num.length();
        int ans = INT_MIN;

        for(int i = 0;i < n;i++){
            ans = max(ans,num[i]-'0');
        }

        return ans;
    }
};