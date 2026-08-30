class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;

        for(int i = 0; i < n; i++)
            arr.push_back(make_pair(nums[i], i));
        
        sort(arr.begin(), arr.end());

        int minValueIdx = arr[0].second;
        int maxValueIdx = arr[n-1].second;

        int lowestIdx = min(minValueIdx, maxValueIdx);
        int highestIdx = max(minValueIdx, maxValueIdx);

        int deleteFromFront = highestIdx + 1;
        int deleteFromBack = n - lowestIdx;
        int deleteFromBothFrontAndBack = (lowestIdx + 1) + (n - highestIdx);

        return min({deleteFromFront, deleteFromBack, deleteFromBothFrontAndBack});
    }
};