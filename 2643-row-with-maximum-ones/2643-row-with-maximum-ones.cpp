class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int row = -1, maxOnes = -1;

        for(int i = 0; i < m; i++){
            int ones = 0;

            for(int j = 0; j < n; j++)
                if(mat[i][j] == 1)
                    ones++;
            
            if(ones > maxOnes){
                maxOnes = ones;
                row = i;
            }
        }

        return {row, maxOnes};
    }
};