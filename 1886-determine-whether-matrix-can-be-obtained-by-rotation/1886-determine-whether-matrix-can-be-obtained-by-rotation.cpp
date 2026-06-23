class Solution {
private:
    void rotate(vector<vector<int>>& mat){
        reverse(mat.begin(),mat.end());
        
        int n = mat.size();

        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target) return true;

        for(int k = 0;k < 3;k++){
            rotate(mat);
            if(mat == target) return true;
        }

        return false;
    }
};