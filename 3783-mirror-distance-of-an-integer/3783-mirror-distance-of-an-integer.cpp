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
    int mirrorDistance(int n) {
        return abs(n - getReverse(n));
    }
};