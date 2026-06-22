class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;

        for(int i = 0;i < n;i++){
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;
        for(int i = 0;i < queries.size();i++){
            int qi = queries[i];
            int ele = nums[qi];
            vector<int> &vec = mp[ele];
            int sz = vec.size();

            if(sz == 1){ // No other occurences
                ans.push_back(-1);
            }
            else{
                int pos = lower_bound(vec.begin(),vec.end(),qi) - vec.begin();
                int res = INT_MAX;

                //Right index Near Pos
                int right = vec[(pos+1)%sz];
                int straightDistRight = abs(qi - right);
                int circularDistRight = (n - straightDistRight);
                res = min({res,straightDistRight,circularDistRight});
 
                //Left index Near Pos
                int left = vec[(pos-1+sz)%sz];
                int straightDistLeft = abs(qi - left);
                int circularDistLeft = (n - straightDistLeft);
                res = min({res,straightDistLeft,circularDistLeft});

                ans.push_back(res);
            }       
        }

        return ans;
    }
};