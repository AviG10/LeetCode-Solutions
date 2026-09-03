class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());

        bool allOdd = false;

        if(nums1[0] % 2 == 1) 
            allOdd = true;
        
        if(allOdd) 
            return true;
        
        bool anyOddPresent = false;
        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i] % 2 == 1){
                anyOddPresent = true;
            }
        }

        if(anyOddPresent)
            return false;
        else 
            return true;
    }
};

