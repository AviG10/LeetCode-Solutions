class Solution {
private:
    void f(int ind, string &s, vector<string> &nums, unordered_map<string,int> &mp){
        if(ind == 0){
            mp[s]++;
            return;
        }
        
        s += '0';
        f(ind-1, s, nums, mp);
        s.pop_back();

        s += '1';
        f(ind-1, s, nums, mp);
        s.pop_back();
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int> mp;
        int n = nums.size();
        string s = "";

        f(n,s,nums,mp);

        for(int i = 0;i < n;i++){
            mp[nums[i]]--;
        }

        for(auto it:mp){
            if(it.second == 1) 
                return it.first;
        }

        return "";

    }
};