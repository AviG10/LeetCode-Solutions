// Layer Traversal of Matrix ( Simulation )
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int layers = min(m/2,n/2);

        for(int layer = 0;layer < layers; layer++){
            int left = layer;
            int right = n-layer-1;
            int top = layer;
            int bottom = m-layer-1;

            vector<int> ly;

            // left to right
            for(int j = left;j <= right;j++){
                ly.push_back(grid[top][j]);
            }

            // top+1 to bottom-1
            for(int j = top+1;j <= bottom-1;j++){
                ly.push_back(grid[j][right]);
            }

            // right to left
            for(int j = right;j >= left;j--){
                ly.push_back(grid[bottom][j]);
            }

            //bottom-1 to top+1
            for(int j = bottom-1;j >= top+1;j--){
                ly.push_back(grid[j][left]);
            }

            int len = ly.size();
            int normalized_k = k % len;
            int idx = 0;

            rotate(ly.begin(),ly.begin() + normalized_k,ly.end());
            
            // left to right
            for(int j = left;j <= right;j++){
                grid[top][j] = ly[idx++];
            }

            // top+1 to bottom-1
            for(int j = top+1;j <= bottom-1;j++){
                grid[j][right] = ly[idx++];
            }

            // right to left
            for(int j = right;j >= left;j--){
                grid[bottom][j] = ly[idx++];
            }

            //bottom-1 to top+1
            for(int j = bottom-1;j >= top+1;j--){
                grid[j][left] = ly[idx++];
            }
        }

        return grid;
    }
};





