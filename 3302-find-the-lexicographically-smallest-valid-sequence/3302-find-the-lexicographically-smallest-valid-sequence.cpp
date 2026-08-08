class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<int> rightCharMatch(m);
        int i = m-1, j = n-1;
        int rightMatch = 0;

        while(i >= 0){
            if(j >= 0 && word1[i] == word2[j]){
                rightMatch++;
                j--;
            }

            rightCharMatch[i] = rightMatch;
            i--;
        }

        bool isChangePossible = true;
        vector<int> seq;
        i = 0, j = 0;

        while(i < m && j < n){
            if(word1[i] == word2[j]){
                seq.push_back(i);
                j++;
            }
            else if(isChangePossible && (i + 1) < m && rightCharMatch[i+1] >= n - j - 1){
                seq.push_back(i);
                j++;
                isChangePossible = false;
            }
            i++;
        }

        return (j == n) ? seq : vector<int>();
    }
};