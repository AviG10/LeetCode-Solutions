class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1 == s2) return true;

        int i = 0,j = 2;

        while(j < 4){
            if(s1[i] != s2[i] || s1[j] != s2[j]){
                swap(s1[i],s1[j]);
                if(s1 == s2) return true;
            }

            i++, j++;
        }
        
        return false;
    }
};