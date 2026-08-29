class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> vec = nums;

        sort(vec.begin(), vec.end());

        int groupNo = 0;
        unordered_map<int, int> numToGroupMapping;
        numToGroupMapping[vec[0]] = groupNo;

        unordered_map<int, deque<int>> groupMapping;
        groupMapping[groupNo].push_back(vec[0]);

        for(int i = 1; i < n; i++){
            if(abs(vec[i] - vec[i-1]) > limit){
                groupNo++;
            }

            numToGroupMapping[vec[i]] = groupNo;
            groupMapping[groupNo].push_back(vec[i]);
        }

        vector<int> result(n, 0);
        for(int i = 0; i < n; i++){
            int group = numToGroupMapping[nums[i]];
            int minOfGroup = groupMapping[group].front();
            
            result[i] = minOfGroup;
            groupMapping[group].pop_front();
        }

        return result;
    }
};