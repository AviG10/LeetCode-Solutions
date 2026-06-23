class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        int ans = n, k = 0;

        while(n){
            ans = (ans ^ (1 << k));
            n = n >> 1;
            k++;
        }

        return ans;
    }
};