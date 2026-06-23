class Solution {
private:
    void addSum(int sum, set<int> &st){
        st.insert(sum);
        if(st.size() > 3) st.erase(st.begin());
    }
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> st;
        vector<vector<int>> cumSum1(m,vector<int>(n,0)); // top-left to botttom-right Diagonal
        vector<vector<int>> cumSum2(m,vector<int>(n,0)); // top-right to bottom-left Diagonal
        
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                cumSum1[i][j] = grid[i][j];
                cumSum2[i][j] = grid[i][j];

                if(i >= 1 && j >= 1) cumSum1[i][j] += cumSum1[i-1][j-1];
                if(i >= 1 && j < n-1) cumSum2[i][j] += cumSum2[i-1][j+1];
            }
        }

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                
                addSum(grid[i][j],st); // rhombus of length 0

                int side = 1;
                while(i-side >= 0 && i+side < m && j-side >= 0 && j+side < n){
                    int sum = 0;

                    // top to left
                    sum += cumSum2[i][j-side];
                    if(i-side-1 >= 0 && j+1 < n){
                        sum -= cumSum2[i-side-1][j+1];
                    }

                    // left to bottom
                    sum += cumSum1[i+side][j];
                    if(i-1 >= 0 && j-side-1 >= 0){
                        sum -= cumSum1[i-1][j-side-1];
                    }

                    // bottom to right
                    sum += cumSum2[i+side][j];
                    if(i-1 >= 0 && j+side+1 < n){
                        sum -= cumSum2[i-1][j+side+1];
                    }

                    // right to top
                    sum += cumSum1[i][j+side];
                    if(i-side-1 >= 0 && j-1 >= 0){
                        sum -= cumSum1[i-side-1][j-1];
                    }

                    // Removing Duplicate counts for corner vertexes
                    sum -= grid[i-side][j]; // top
                    sum -= grid[i][j-side]; // left
                    sum -= grid[i+side][j]; // bottom
                    sum -= grid[i][j+side]; // right

                    addSum(sum,st);
                    side++;
                }
            }
        }

        return vector<int>(rbegin(st),rend(st));
    }
}; 