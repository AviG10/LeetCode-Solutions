class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        vector<double> prev(query_glass+2,0.0), cur(query_glass+2,0.0);
        
        cur[1] = poured;

        for(int i = 1;i < query_row+2;i++){
            for(int j = 1;j < query_glass+2;j++){
                
                if(i == 1 && j == 1) continue;

                double prev_left = (prev[j-1]-1)/2.0;
                double prev_right = (prev[j]-1)/2.0;

                if(prev_left < 0) prev_left = 0.0;
                if(prev_right < 0) prev_right = 0.0;

                cur[j] = prev_left + prev_right;
            }

            prev = cur;
        }

        double temp_ans = prev[query_glass+1];

        return temp_ans > 1.0 ? 1.0 : temp_ans;
    }
};