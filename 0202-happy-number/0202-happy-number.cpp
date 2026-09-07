class Solution {
private:
    int squareSum(int num){
        int result = 0;

        while(num > 0){
            int rem = num % 10;
            num /= 10;
            result += rem * rem;
        }

        return result;
    }
public:
    bool isHappy(int n) {
        if(n == 1 || squareSum(n) == 1)
            return true;
        
        int slow = n;
        int fast = n;
        
        while(fast != 1 && squareSum(fast) != 1){
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));

            if(slow == fast)
                return false;
        }

        return true;
    }
};