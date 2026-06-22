class Solution {
private:
    long long f(int i, int trend, int &n, vector<int> &nums, vector<vector<long long>> &dp){
        if(i == n){
            if(trend == 3) return 0;
            else return LLONG_MIN/2;
        }

        if(dp[i][trend] != -1) return dp[i][trend];

        long long trend0 = LLONG_MIN/2;
        long long trend1 = LLONG_MIN/2;
        long long trend2 = LLONG_MIN/2;
        long long trend3 = LLONG_MIN/2;

        if(trend == 0){
            trend0 = max(trend0,f(i+1,0,n,nums,dp));

            if(i+1 < n && nums[i+1] > nums[i]){
                trend0 = max(trend0, nums[i] + f(i+1,1,n,nums,dp));
            }
        }
        else if(trend == 1){
            if(i+1 < n && nums[i+1] > nums[i]){
                trend1 = max(trend1, nums[i] + f(i+1,1,n,nums,dp));
            } 
            else if(i+1 < n && nums[i+1] < nums[i]){
                trend1 = max(trend1, nums[i] + f(i+1,2,n,nums,dp));
            }
        }
        else if(trend == 2){
            if(i+1 < n && nums[i+1] < nums[i]){
                trend2 = max(trend2, nums[i] + f(i+1,2,n,nums,dp));
            } 
            else if(i+1 < n && nums[i+1] > nums[i]){
                trend2 = max(trend2, nums[i] + f(i+1,3,n,nums,dp));
            }
        }
        else{
            trend3 = max(trend3,(long long)nums[i]);

            if(i+1 < n && nums[i+1] > nums[i]){
                trend3 = max(trend3, nums[i] + f(i+1,3,n,nums,dp));
            }
        }

        return dp[i][trend] = max(trend0,max(trend1,max(trend2,trend3)));
    }
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prev(4,LLONG_MIN/2), cur(4,LLONG_MIN/2);
        prev[3] = 0;
        
        for(int i = n-1;i >= 0;i--){
            for(int trend = 0;trend < 4;trend++){
                long long trend0 = LLONG_MIN/2;
                long long trend1 = LLONG_MIN/2;
                long long trend2 = LLONG_MIN/2;
                long long trend3 = LLONG_MIN/2;

                if(trend == 0){
                    trend0 = max(trend0,prev[0]);

                    if(i+1 < n && nums[i+1] > nums[i]){
                        trend0 = max(trend0, nums[i] + prev[1]);
                    }
                }
                else if(trend == 1){
                    if(i+1 < n && nums[i+1] > nums[i]){
                        trend1 = max(trend1, nums[i] + prev[1]);
                    } 
                    else if(i+1 < n && nums[i+1] < nums[i]){
                        trend1 = max(trend1, nums[i] + prev[2]);
                    }
                }
                else if(trend == 2){
                    if(i+1 < n && nums[i+1] < nums[i]){
                        trend2 = max(trend2, nums[i] + prev[2]);
                    } 
                    else if(i+1 < n && nums[i+1] > nums[i]){
                        trend2 = max(trend2, nums[i] + prev[3]);
                    }
                }
                else{
                    trend3 = max(trend3,(long long)nums[i]);

                    if(i+1 < n && nums[i+1] > nums[i]){
                        trend3 = max(trend3, nums[i] + prev[3]);
                    }
                }

                cur[trend] = max(trend0,max(trend1,max(trend2,trend3)));
            }
            prev = cur;
        }

        return prev[0];
    }
};