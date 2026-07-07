class Solution {
private:    
    void buildNewNum(int n, int &newNum, int &sum){
        int multiplier = 1;

        while(n > 0){
            int rem = n % 10;
            
            if(rem != 0){
                newNum = rem * multiplier + newNum;
                sum += rem;
                multiplier *= 10;
            } 

            n /= 10; 
        }
    }
public:
    long long sumAndMultiply(int n) {
        int newNum = 0;
        int sum = 0;

        buildNewNum(n, newNum, sum);

        return (long long)newNum * sum;
    }
};