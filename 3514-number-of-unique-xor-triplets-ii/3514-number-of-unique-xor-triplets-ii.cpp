// Better
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 1;

        unordered_set<int> st;

        for(int i = 0;i < n;i++){
            for(int j = i;j < n;j++){
                st.insert(nums[i] ^ nums[j]);
            }
        }

        unordered_set<int> result;
        for(auto it: st){
            for(int k = 0; k < n;k++){
                result.insert(it ^ nums[k]);
            }
        }

        return result.size();
    }
};