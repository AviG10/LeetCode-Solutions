class Solution {
public:
    string stoneGameIII(vector<int>& stones) {
        int n = stones.size();
        int cur = 0, later1 = 0, later2 = 0, later3 = 0;

        for(int i = n-1;i >= 0;i--){
            int result = INT_MIN;

            result = max(result, stones[i] - later1);

            if (i + 1 < n)
                result = max(result, stones[i] + stones[i + 1] -
                                        later2);

            if (i + 2 < n)
                result = max(result, stones[i] + stones[i + 1] + stones[i + 2] -
                                       later3);

            cur = result;

            later3 = later2;
            later2 = later1;
            later1 = cur;
        }

        int diffSum = cur;

        if (diffSum > 0)
            return "Alice";
        else if (diffSum < 0)
            return "Bob";
        else
            return "Tie";
    }
};