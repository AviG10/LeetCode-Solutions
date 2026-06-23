class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();

        for(int i = 0;i < m;i++){
            int shiftCnt = k % n;

            for(int j = 0;j < n;j++){

                if(i % 2 == 0){
                    int col = j - shiftCnt;
                    if(col < 0) col += n;
                    if(mat[i][j] != mat[i][col]) return false;
                }
                else{
                    int col = j + shiftCnt;
                    if(col >= n) col -= n;
                    if(mat[i][j] != mat[i][col]) return false;
                }
            }
        }

        return true;
    }
};