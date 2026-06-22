class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        set<string> st;
        int cnt = (1 << k);

        for(int i = k;i <= n;i++){
            string temp = s.substr(i-k,k);
            st.insert(temp);
            if(st.size() == cnt) return true;
        }

        return false;
    }
};