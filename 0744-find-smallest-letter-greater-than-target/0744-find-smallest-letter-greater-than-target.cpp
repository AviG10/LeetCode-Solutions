class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = target;

        for(int i = 0;i < letters.size();i++){
            if(letters[i] > target){
                if(ans != target){
                    if(letters[i] < ans) ans = letters[i];
                }
                else ans = letters[i];
            }
        }

        if(ans == target) return letters[0];
        else return ans;
    }
};