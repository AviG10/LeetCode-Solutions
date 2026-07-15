class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0, sumEven = 0;
        int startOdd = 1, startEven = 2;

        for(int i = 1;i <= n;i++){
            sumOdd += startOdd;
            sumEven += startEven;

            startOdd += 2;
            startEven += 2;
        }

        return __gcd(sumOdd, sumEven);
    }
};