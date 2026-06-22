class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int prevStreak = 0, curStreak = 1;
        int ans = 0;

        for(int i = 1;i < n;i++){
            if(s[i] == s[i-1]){
                curStreak++;
            }
            else{
                ans += min(prevStreak,curStreak);
                prevStreak = curStreak;
                curStreak = 1;
            }
        }
        ans += min(prevStreak,curStreak);

        return ans;
    }
};