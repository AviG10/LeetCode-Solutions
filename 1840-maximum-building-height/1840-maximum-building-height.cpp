class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});

        sort(begin(restrictions), end(restrictions));

        int N = restrictions.size();

        for (int i = 1; i < N; i++) {
            int distDiff = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i - 1][1] + distDiff);
        }

        for (int i = N - 2; i >= 1; i--) {
            int distDiff = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i + 1][1] + distDiff);
        }

        int result = 0;

        for (int i = 1; i < N; i++) {
            int leftPos = restrictions[i - 1][0];
            int leftHt = restrictions[i - 1][1];

            int curPos = restrictions[i][0];
            int curHt = restrictions[i][1];

            int posDiff = (curPos - leftPos);
            int htDiff = abs(leftHt - curHt);

            int peakHt = max(leftHt, curHt) + (posDiff - htDiff) / 2;

            result = max(result, peakHt);
        }

        return result;
    }
};