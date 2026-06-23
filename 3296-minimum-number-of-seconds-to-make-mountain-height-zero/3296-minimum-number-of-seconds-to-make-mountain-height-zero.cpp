class Solution {
private:
    bool checkIfPossible(int &k, vector<int>& nums, long long mid){
        int h = 0;
        int n = nums.size();

        for(int i = 0;i < n;i++){
            h += (long long)(sqrt(2.0 * mid/nums[i] + 0.25) - 0.5);

            if(h >= k) return true;
        }

        return (h >= k);
    }
public:
    long long minNumberOfSeconds(int k, vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();

        for(int i = 0;i < n;i++){
            maxi = max(maxi,nums[i]);
        }

        long long low = 1, high = (long long)maxi * k * (k+1)/2;

        while(low <= high){
            long long mid = low + (high-low)/2;

            if(checkIfPossible(k,nums,mid))
                high = mid-1;
            else
                low = mid+1;
        }
        
        return low;
    }   
};