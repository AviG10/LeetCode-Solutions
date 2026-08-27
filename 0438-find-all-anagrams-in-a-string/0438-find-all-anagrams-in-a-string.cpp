class Solution {
private:    
    bool allZeros(vector<int> & counter){
        for(int it : counter){
            if(it != 0)
                return false;
        }

        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> counter(26,0);
        int n = s.length(), m = p.length();

        for(int i = 0; i < m; i++){
            counter[p[i] - 'a']++;
        }

        int i = 0, j = 0;
        vector<int> result;

        while(j < n){
            counter[s[j] - 'a']--;

            if(j - i + 1 == m){
                if(allZeros(counter)){
                    result.push_back(i);
                }   

                counter[s[i] - 'a']++;
                i++;
            }

            j++;
        }

        return result;
    }
};