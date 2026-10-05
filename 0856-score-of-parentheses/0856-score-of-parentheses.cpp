class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(ans);
                ans = 0;
            } else {
                if (ans == 0)
                    ans = st.top() + 1;
                else
                    ans = st.top() + (2 * ans);

                st.pop();
            }
        }
        return ans;
    }
};