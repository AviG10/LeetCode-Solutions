class Solution {
private:
    bool isPossible(vector<vector<int>>& tasks, int mid){
        int n = tasks.size();

        for(int i = 0;i < n;i++){
            if(tasks[i][1] > mid) return false;
            mid -= tasks[i][0];
        }

        return true;
    }
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(),tasks.end(),[](vector<int> &a, vector<int> &b){
            int diff1 = a[1]-a[0];
            int diff2 = b[1]-b[0];

            return diff1 > diff2;
        });

        int low = 0;
        int high = 1e9;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isPossible(tasks,mid)) high = mid-1;
            else low = mid+1;
        }

        return low;
    }
};