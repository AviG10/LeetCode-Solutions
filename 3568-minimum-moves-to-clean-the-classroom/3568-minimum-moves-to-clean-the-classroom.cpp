class Solution {
private:
    struct State {
        int row;
        int col;
        int energyLeft;
        int mask;
    };

    bool isValid(int row, int col, int& m, int& n) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }

public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int maxEnergy = energy;

        vector<vector<int>> litterBit(m, vector<int>(n, -1));
        int startR = -1, startC = -1;
        int litterCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    startR = i;
                    startC = j;
                } else if (classroom[i][j] == 'L') {
                    litterBit[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        if (litterCount == 0)
            return 0;

        int allLitterCollected = (1 << litterCount) - 1;

        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                   n, vector<vector<bool>>(
                          maxEnergy + 1,
                          vector<bool>(allLitterCollected + 1, false))));

        queue<State> q;
        int moves = 0;

        q.push({startR, startC, maxEnergy, 0});
        visited[startR][startC][maxEnergy][0] = true;

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                State cur = q.front();
                q.pop();

                if (cur.mask == allLitterCollected)
                    return moves;

                if (cur.energyLeft == 0)
                    continue;

                for (auto& dir : directions) {
                    int nextRow = cur.row + dir[0];
                    int nextCol = cur.col + dir[1];
                    int nextEnergy = cur.energyLeft - 1;
                    int nextMask = cur.mask;

                    if (isValid(nextRow, nextCol, m, n) &&
                        classroom[nextRow][nextCol] != 'X') {
                        int cellVal = classroom[nextRow][nextCol];

                        if (cellVal == 'R')
                            nextEnergy = maxEnergy;
                        else if (cellVal == 'L')
                            nextMask =
                                nextMask | (1 << litterBit[nextRow][nextCol]);

                        if (!visited[nextRow][nextCol][nextEnergy][nextMask]) {
                            visited[nextRow][nextCol][nextEnergy][nextMask] =
                                true;
                            q.push({nextRow, nextCol, nextEnergy, nextMask});
                        }
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};