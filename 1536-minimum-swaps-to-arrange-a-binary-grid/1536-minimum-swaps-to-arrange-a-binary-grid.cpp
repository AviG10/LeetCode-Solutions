class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeros(n);

        for(int i = 0;i < n;i++){
            int cnt = 0;
            for(int j = n-1;j >= 0;j--){
                if(grid[i][j] == 0) cnt++;
                else break;
            }
            trailingZeros[i] = cnt;
        }

        int cntSwap = 0;
        for(int i = 0;i < n;i++){
            int needZeros = n-i-1;
            int swapInd = -1;

            for(int j = i;j < n;j++){
                if(trailingZeros[j] >= needZeros){
                    swapInd = j;
                    break;
                }
            }

            if(swapInd == -1) return swapInd;
            else {
                cntSwap += (swapInd-i);
                
                for(int j = swapInd;j > i;j--){
                    swap(trailingZeros[j],trailingZeros[j-1]);
                }
            }
        }
        
        return cntSwap;
    }
};