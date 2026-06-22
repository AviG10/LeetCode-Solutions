class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        int colStart = 0, colEnd = n-1;

        while(colStart < colEnd){
            for(int i = 0;i < n;i++){
                swap(matrix[i][colStart], matrix[i][colEnd]);
            }
            colStart++, colEnd--;
        }
    }
};