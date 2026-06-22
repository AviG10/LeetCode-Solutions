class Solution {
private:
    int getWaviness(int num){
        string numStr = to_string(num);
        int n = numStr.length();

        if(n < 3) return 0;

        int peak = 0, valley = 0;

        for(int i = 1;i < n-1;i++){
            if(numStr[i] > numStr[i-1] && numStr[i] > numStr[i+1]) peak++;
            if(numStr[i] < numStr[i-1] && numStr[i] < numStr[i+1]) valley++;
        }

        return peak + valley;
    }
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        
        for(int i = num1;i <= num2;i++){
            ans += getWaviness(i);
        }

        return ans;
    }
};