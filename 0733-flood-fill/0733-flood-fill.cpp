class Solution {
private:
    bool isValid(int i, int j, int &m, int &n, vector<vector<int>> &image, int &prevColor){
        if(i >= 0 && i < m && j >= 0 && j < n && image[i][j] == prevColor)
            return true;
        else
            return false;
    }

    void dfs(int i, int j, int &m, int &n, vector<vector<int>> &image, int &color, int &prevColor){
        image[i][j] = color;

        if(isValid(i + 1, j, m, n, image, prevColor))
            dfs(i + 1, j, m, n, image, color, prevColor);
        
        if(isValid(i - 1, j, m, n, image, prevColor))
            dfs(i - 1, j, m, n, image, color, prevColor);

        if(isValid(i, j + 1, m, n, image, prevColor))
            dfs(i, j + 1, m, n, image, color, prevColor);

        if(isValid(i, j - 1, m, n, image, prevColor))
            dfs(i, j - 1, m, n, image, color, prevColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prevColor = image[sr][sc];
        
        if(prevColor == color)
            return image;
        
        int m = image.size();
        int n = image[0].size();

        dfs(sr, sc, m, n, image, color, prevColor);
        return image;
    }
};