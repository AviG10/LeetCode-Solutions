class Solution {
private:
    int dirX[4] = {1, 0, -1, 0};

    int dirY[4] = {0, 1, 0, -1};

    bool isValid(int& x, int& y, int& n) {
        return (x >= 0 && x < n && y >= 0 && y < n);
    }

    void buildSafenessScore(vector<vector<int>>& safenessScore,
                            vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        int level = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto it = q.front();
                q.pop();

                int x = it.first;
                int y = it.second;

                safenessScore[x][y] = level;

                for (int i = 0; i < 4; i++) {
                    int newX = x + dirX[i];
                    int newY = y + dirY[i];

                    if (isValid(newX, newY, n) && !vis[newX][newY]) {
                        q.push({newX, newY});
                        vis[newX][newY] = true;
                    }
                }
            }

            level++;
        }
    }

    bool checkSafenessFactor(vector<vector<int>>& safenessScore, int mid) {
        int n = safenessScore.size();

        if (safenessScore[0][0] < mid || safenessScore[n - 1][n - 1] < mid)
            return false;

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        q.push({0, 0});
        vis[0][0] = true;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto it = q.front();
                q.pop();

                int x = it.first;
                int y = it.second;

                if (x == n - 1 && y == n - 1)
                    return true;

                for (int i = 0; i < 4; i++) {
                    int newX = x + dirX[i];
                    int newY = y + dirY[i];

                    if (isValid(newX, newY, n) && !vis[newX][newY]) {
                        if (safenessScore[newX][newY] >= mid) {
                            q.push({newX, newY});
                            vis[newX][newY] = true;
                        }
                    }
                }
            }
        }

        return false;
    }

    int findMaximumSafenessFactor(vector<vector<int>>& safenessScore) {
        int n = safenessScore.size();
        int low = 0;
        int high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (checkSafenessFactor(safenessScore, mid))
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> safenessScore(n, vector<int>(n, 0));

        buildSafenessScore(safenessScore, grid);

        return findMaximumSafenessFactor(safenessScore);
    }
};