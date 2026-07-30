class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();

        if(n <= 8) 
            return n;
        else if(n >= 9 && n <= 16)
            return 8 + 2 * (n - 8);
        else if(n >= 17 && n <= 24)
            return 8 + 2 * 8 + 3 * (n-16);
        else 
            return 8 + 2 * 8 + 3 * 8 + 4 * (n-24);  
    }
};
