class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cummulativeSum(n, 0);
        deque<int> deq;

        int result = INT_MAX;
        int i = 0;

        while(i < n){
            if(i == 0)
                cummulativeSum[i] = nums[i];
            else
                cummulativeSum[i] = cummulativeSum[i-1] + nums[i];
            
            if(cummulativeSum[i] >= k) 
                result = min(result, i + 1);
            
            while(!deq.empty() && cummulativeSum[i] - cummulativeSum[deq.front()] >= k){
                result = min(result, i - deq.front());
                deq.pop_front();
            }

            while(!deq.empty() && cummulativeSum[i] <= cummulativeSum[deq.back()]){
                deq.pop_back();
            }

            deq.push_back(i);
            i++;
        }

        return result == INT_MAX ? -1 : result;
    }
};