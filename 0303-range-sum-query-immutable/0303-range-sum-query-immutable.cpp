class NumArray {
private:
    vector<int> prefixSum;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();

        prefixSum.resize(n, 0);
        prefixSum[0] = nums[0];

        for(int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i-1] + nums[i];
    }
    
    int sumRange(int left, int right) {
        if(left == 0) 
            return prefixSum[right];
        else
            return prefixSum[right] - prefixSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */