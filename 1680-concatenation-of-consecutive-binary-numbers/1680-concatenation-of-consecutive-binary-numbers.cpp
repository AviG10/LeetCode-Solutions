class Solution {
public:
    int concatenatedBinary(int n) {
        int cntBits = 0;
        long long ans = 0;
        int MOD = 1e9+7;

        for(int num = 1;num <= n;num++){
            if((num & (num-1)) == 0) cntBits++;
            ans = ((ans << cntBits)% MOD + num )% MOD;
        }

        return ans;
    }
};