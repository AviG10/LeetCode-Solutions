class Solution {
public:
    bool sumGame(string s) {
        int n = s.length();
        int firstHalfSum = 0, secondHalfSum = 0;
        int firstHalfTotalQuestionMarks = 0, secondHalfTotalQuestionMarks = 0;

        for(int i = 0; i < n / 2; i++){
            if(s[i] == '?') 
                firstHalfTotalQuestionMarks++;
            else
                firstHalfSum += s[i] - '0';
        }

        for(int i = n/2; i < n; i++){
            if(s[i] == '?') 
                secondHalfTotalQuestionMarks++;
            else
                secondHalfSum += s[i] - '0';
        }

        if((firstHalfTotalQuestionMarks + secondHalfTotalQuestionMarks) == 0)
            return (firstHalfSum != secondHalfSum);
        
        if((firstHalfTotalQuestionMarks + secondHalfTotalQuestionMarks) % 2 == 1)
            return true;
        
        if(firstHalfTotalQuestionMarks > secondHalfTotalQuestionMarks){
            swap(firstHalfTotalQuestionMarks, secondHalfTotalQuestionMarks);
            swap(firstHalfSum, secondHalfSum);
        }
        
        secondHalfTotalQuestionMarks -= firstHalfTotalQuestionMarks;

        if(firstHalfSum < secondHalfSum) return true;
        else if(9 * (secondHalfTotalQuestionMarks/2) == (firstHalfSum - secondHalfSum)) return false;
        else return true;
    }
};