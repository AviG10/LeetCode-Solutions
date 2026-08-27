class Solution {
private:
    int findNext(int j, char c, string &t){
        if(j == t.length())
            return -1;
        
        if(c == t[j]) 
            return j;
        
        return findNext(j+1, c, t);
    }
public:
    bool isSubsequence(string s, string t) {
        int cur_j = 0;

        for(char &ch : s){
            int next_idx = findNext(cur_j, ch, t);
            
            if(next_idx == -1) 
                return false;
            else
                cur_j = next_idx + 1;
        }

        return true;
    }
};