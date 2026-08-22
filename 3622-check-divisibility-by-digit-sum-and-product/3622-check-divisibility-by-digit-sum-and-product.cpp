class Solution {
public:
    bool checkDivisibility(int num) {
        int digitSum = 0;
        int digitProduct = 1;
        int n = num;

        while(n > 0){
            int rem = n % 10;
            
            digitSum += rem;
            digitProduct *= rem;

            n /= 10;
        }
        
        int totalSum = digitSum + digitProduct;
        
        return (num % totalSum == 0) ? true : false;
    }
};