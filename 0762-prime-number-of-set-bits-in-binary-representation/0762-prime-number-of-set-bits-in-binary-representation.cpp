class Solution {
private:
    bool isPrime(int num){
        if(num <= 1) return false;

        for(int i = 2;i*i <= num;i++){
            if(num%i == 0) return false;
        }

        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;

        for(int i = left;i <= right;i++){
            int cnt = __builtin_popcount(i);

            if(isPrime(cnt)) ans++;
        }

        return ans;
    }
};