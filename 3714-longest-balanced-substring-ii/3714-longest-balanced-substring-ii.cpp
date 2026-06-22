class Solution {
private:
    // Case - 1
    int longestBalaceSubStr1Char(string &s){
        int n = s.length();
        int cnt = 1, maxLen = 1;

        for(int i = 1;i < n;i++){
            if(s[i] == s[i-1]) cnt++;
            else cnt = 1;
            maxLen = max(maxLen,cnt);
        }

        return maxLen;

    }

    // Case - 2
    int longestBalaceSubStr2Char(string &s, char ch1, char ch2){
        int n = s.length();
        int cnt1 = 0, cnt2 = 0;
        unordered_map<int,int> mp;
        int maxLen = 0;

        for(int i = 0;i < n;i++){
            if(s[i] != ch1 && s[i] != ch2) {
                cnt1 = 0;
                cnt2 = 0;
                mp.clear();
            }
            else{
                if(s[i] == ch1) cnt1++;
                if(s[i] == ch2) cnt2++;

                if(cnt1 == cnt2) maxLen = max(maxLen,cnt1+cnt2);
                else{
                    int diff = cnt1-cnt2;

                    if(mp.count(diff)) maxLen = max(maxLen,i - mp[diff]);
                    else mp[diff] = i;
                }
            }
        }

        return maxLen;
    }

    // Case - 3
    int longestBalaceSubStr3Char(string &s){
        int n = s.length();
        int cntA = 0, cntB = 0, cntC = 0;
        int maxLen = 0;
        map<pair<int,int>,int> mp;

        for(int i = 0;i < n;i++){
            if(s[i] == 'a') cntA++;
            else if(s[i] == 'b') cntB++;
            else cntC++;

            if(cntA == cntB && cntB == cntC) maxLen = max(maxLen,cntA+cntB+cntC);
            else{
                pair<int,int> diff = {cntA-cntB,cntB-cntC};

                if(mp.count(diff)) maxLen = max(maxLen,i - mp[diff]);
                else mp[diff] = i;
            }
        }

        return maxLen;
    }

public:
    int longestBalanced(string s) {

        int ans = 0;

        // Case-1 ( longest Balance Substring formed by only 1 character )
        ans = max(ans,longestBalaceSubStr1Char(s)); // O(n)

        // Case-2 ( longest Balance Substring formed by only 2 character )
        ans = max(ans,longestBalaceSubStr2Char(s,'a','b')); // O(n)
        ans = max(ans,longestBalaceSubStr2Char(s,'b','c')); // O(n)
        ans = max(ans,longestBalaceSubStr2Char(s,'c','a')); // O(n)

        // Case-3 ( longest Balance Substring formed by only 3 character )
        ans = max(ans,longestBalaceSubStr3Char(s)); // O(n logn)

        return ans;
    }
};