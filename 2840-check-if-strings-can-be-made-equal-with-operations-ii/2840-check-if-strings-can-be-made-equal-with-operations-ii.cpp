class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        unordered_map<char,int> evenMp,oddMp;
        
        // Even Index
        int idxEven = 0;
        while(idxEven < n){
            evenMp[s1[idxEven]]++;
            idxEven += 2;
        }

        idxEven = 0;
        while(idxEven < n){
            evenMp[s2[idxEven]]--;
            idxEven += 2;
        }

        for(auto it: evenMp){
            if(it.second != 0) return false;
        }

        // Odd Index
        int idxOdd = 1;
        while(idxOdd < n){
            oddMp[s1[idxOdd]]++;
            idxOdd += 2;
        }

        idxOdd = 1;
        while(idxOdd < n){
            oddMp[s2[idxOdd]]--;
            idxOdd += 2;
        }

        for(auto it: oddMp){
            if(it.second != 0) return false;
        }

        return true;
    }
};