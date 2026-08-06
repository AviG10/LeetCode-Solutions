class Solution {
private:
    int productOfDigits(int num){
        int prod = 1;

        while(num > 0){
            int digit = num % 10;
            prod *= digit;
            num /= 10;
        }

        return prod;
    }
public:
    int smallestNumber(int n, int t) {
        int ans;
        
        for(int num = n;num <= 100;num++){
            if(productOfDigits(num) % t == 0){
                ans = num;
                break;
            }
        }

        return ans;
    }
};