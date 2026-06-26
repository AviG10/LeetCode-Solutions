class Solution {
    public boolean isValid(String s) {
        int n = s.length();
        Deque<Character> st = new ArrayDeque<>();

        for(int i = 0;i < n;i++){
            if(st.isEmpty() || s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '['){
                st.push(s.charAt(i));
                continue;
            }

            if(s.charAt(i) == ')'){
                if(st.peek() == '(')
                    st.pop();
                else 
                    return false;
            }

            if(s.charAt(i) == '}'){
                if(st.peek() == '{')
                    st.pop();
                else 
                    return false;
            }

            if(s.charAt(i) == ']'){
                if(st.peek() == '[')
                    st.pop();
                else 
                    return false;
            }
        }

        return st.isEmpty();
    }
}