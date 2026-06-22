class Solution {
public:
    string processStr(string s) {
        string result = "";
        int n = s.length();

        for(int i = 0;i < n;i++){
            if(s[i] == '*' && result != "") result.pop_back();
            if(s[i] == '#') result = result + result;
            if(s[i] == '%') reverse(result.begin(),result.end());
            if(islower(s[i])) result += s[i];
        }

        return result;
    }
};