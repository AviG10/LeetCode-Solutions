// Space Optimization
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        vector<int> factoryExpand;
        int m = robot.size(), n = factory.size();

        for(int i = 0;i < n;i++){
            int pos = factory[i][0];
            int limit = factory[i][1];

            for(int j = 0;j < limit;j++){
                factoryExpand.push_back(pos);
            }
        }

        n = factoryExpand.size();
        vector<long long> cur(n+1,0), next(n+1,0);
        
        cur[n] = 1e13;

        for(int i = m-1;i >= 0;i--){
            for(int j = n-1;j >= 0;j--){
                long long take = abs(robot[i]-factoryExpand[j]) + next[j+1];
                long long notTake = cur[j+1];

                cur[j] = min(take,notTake);
            }
            next = cur;
        }

        return next[0];
    }
};