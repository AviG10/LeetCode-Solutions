class Solution {
private:
    string s;
    int n;
    long long dpTotalNumbers[16][10][10][2][2], dpTotalWavinessScore[16][10][10][2][2];

    pair<long long, long long> solve(int curIdx, int prevPrev, int prev, bool isLimitedWithActualNumber, bool isLeadingZero){
        if(curIdx == n) 
            return {1,0};

        if(prevPrev >= 0 && prev >= 0 && dpTotalNumbers[curIdx][prevPrev][prev][isLimitedWithActualNumber][isLeadingZero] != -1 
            && dpTotalWavinessScore[curIdx][prevPrev][prev][isLimitedWithActualNumber][isLeadingZero] != -1)
            
            return {dpTotalNumbers[curIdx][prevPrev][prev][isLimitedWithActualNumber][isLeadingZero], dpTotalWavinessScore[curIdx][prevPrev][prev][isLimitedWithActualNumber][isLeadingZero]};
        
        long long totalNumbers = 0;
        long long totalWavinessScore = 0;

        int limitDigit = isLimitedWithActualNumber ? (s[curIdx] - '0') : 9;

        for(int digit = 0;digit <= limitDigit;digit++){
            
            bool newIsLeadingZero = isLeadingZero && (digit == 0);
            int newPrevPrev = prev;
            int newPrev = newIsLeadingZero ? -1 : digit;
            bool newIsLimitedWithActualNumber = isLimitedWithActualNumber && (digit == limitDigit);

            auto [remainingTotalNumbers, remainingTotalWavinessScore] = solve(curIdx+1,newPrevPrev,newPrev,newIsLimitedWithActualNumber,newIsLeadingZero);

            if(newIsLeadingZero == false && prevPrev >= 0 && prev >= 0){
                bool isPeak = ( prevPrev < prev && prev > digit );
                bool isValley = ( prevPrev > prev && prev < digit );

                totalWavinessScore += (isPeak || isValley) ? remainingTotalNumbers : 0;
            }

            totalNumbers += remainingTotalNumbers;
            totalWavinessScore += remainingTotalWavinessScore;
        }

        if(prevPrev >= 0 && prev >= 0){
            dpTotalNumbers[curIdx][prevPrev][prev][isLimitedWithActualNumber][isLeadingZero] = totalNumbers;
            dpTotalWavinessScore[curIdx][prevPrev][prev][isLimitedWithActualNumber][isLeadingZero] = totalWavinessScore;
        }

        return {totalNumbers, totalWavinessScore};
    }

    long long helper(long long num) {
        if (num < 100)
            return 0;

        s = to_string(num);
        n = s.length();

        memset(dpTotalNumbers, -1, sizeof(dpTotalNumbers));
        memset(dpTotalWavinessScore, -1, sizeof(dpTotalWavinessScore));

        auto [totalNumbers, totalWavinessScore] = solve(0, -1, -1, true, true);

        return totalWavinessScore;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return helper(num2) - helper(num1 - 1);
    }
};