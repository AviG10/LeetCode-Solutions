class Solution {
public:
    int maxDepth(string s) {
        int n = s.size(),depth = 0;
        stack<char> st;
        
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(')
                st.push('(');
            
            if(s[i] == ')')
                st.pop();

            int temp = st.size();
            depth = max(depth , temp); 
        }
        
        return depth;
    }
};