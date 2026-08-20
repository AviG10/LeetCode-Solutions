class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        int lastidx1 = 0, lastidx2 = 0;

        for(int i = 2;i < n;i++){
            if(arr1[lastidx1] > arr2[lastidx2]){
                arr1.push_back(nums[i]);
                lastidx1++;
            }
            else{
                arr2.push_back(nums[i]);
                lastidx2++;
            }
        }

        vector<int> result;
        
        int ind = 0;
        while(ind < arr1.size()){
            result.push_back(arr1[ind]);
            ind++;
        }

        ind = 0;
        while(ind < arr2.size()){
            result.push_back(arr2[ind]);
            ind++;
        }

        return result;
    }
};