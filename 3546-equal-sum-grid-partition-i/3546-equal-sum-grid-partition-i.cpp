class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<long long> rowSum(m,0), colSum(n,0);

        long long totalSum = 0;
        for(int i = 0;i < m;i++){
            long long rowPrefixSum = 0;
            
            for(int j = 0;j < n;j++){
                rowPrefixSum += grid[i][j];
            }
            
            totalSum += rowPrefixSum;
            rowSum[i] = rowPrefixSum;
        }

        if(totalSum % 2 != 0) return false;

        for(int j = 0;j < n;j++){
            long long colPrefixSum = 0;

            for(int i = 0;i < m;i++){
                colPrefixSum += grid[i][j];
            }

            colSum[j] = colPrefixSum;
        }

        if(rowSum[0] == (totalSum - rowSum[0])) return true;

        for(int i = 1;i < m;i++){
            rowSum[i] += rowSum[i-1];
            
            if(rowSum[i] == (totalSum - rowSum[i])) return true;
        }

        if(colSum[0] == (totalSum - colSum[0])) return true;

        for(int j = 1;j < n;j++){
            colSum[j] += colSum[j-1];
            
            if(colSum[j] == (totalSum - colSum[j])) return true;
        }

        return false;
    }
};