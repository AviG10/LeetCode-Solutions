class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> nums = arr;
        unordered_map<int, int> mp;

        sort(nums.begin(), nums.end());
        
        int rank = 1;

        for(auto num: nums){
            if(!mp.count(num)){
                mp[num] = rank; 
                rank++;
            }   
        }

        vector<int> ans;

        for(auto it: arr){
            ans.push_back(mp[it]);
        }

        return ans;
    }
};