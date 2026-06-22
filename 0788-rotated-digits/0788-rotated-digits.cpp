class Solution {
private:
    bool checkGood(int num){
        bool rotateNum = false;

        while(num > 0){
            int rem = num%10;
            num /= 10;
            if(rem == 3 || rem == 4 || rem == 7) return false;
            if(rem == 2 || rem == 5 || rem == 6 || rem == 9) rotateNum = true;
        }

        return rotateNum;
    }
public:
    int rotatedDigits(int n) {
        int count = 0;

        for(int num = 1;num <= n;num++){
            if(checkGood(num)){
                count++;
            }         
        }

        return count;
    }
};