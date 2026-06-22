// Space Optimization
class Solution {
private:
    int countWalls(vector<int> &walls, int left, int right){
        int leftInd = lower_bound(walls.begin(),walls.end(),left) - walls.begin();
        int rightInd = upper_bound(walls.begin(),walls.end(),right) - walls.begin();

        return (rightInd - leftInd);
    }
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<pair<int,int>> robotDist;

        for(int i = 0;i < n;i++){
            robotDist.push_back({robots[i],distance[i]});
        }

        sort(robotDist.begin(),robotDist.end());
        sort(walls.begin(),walls.end());

        vector<pair<int,int>> range;

        for(int i = 0;i < n;i++){
            int robotPos = robotDist[i].first;
            int dist = robotDist[i].second;

            int leftLimit = (i == 0) ? 1 : robotDist[i-1].first+1;
            int rightLimit = (i == n-1) ? 1e9 : robotDist[i+1].first-1;

            int L = max(robotPos - dist, leftLimit);
            int R = min(robotPos + dist, rightLimit);

            range.push_back({L,R});
        }

        vector<int> cur(2,-1),prev(2,-1);

        cur[0] = cur[1] = 0;

        for(int i = n-1;i >= 0;i--){
            for(int prevDir = 0;prevDir < 2;prevDir++){
                int leftRange = range[i].first;

                if(prevDir == 1){ // Previous travelled in right direction
                    if(i > 0) leftRange = max(leftRange, range[i-1].second + 1);
                }

                int leftWalls = countWalls(walls,leftRange,robotDist[i].first) 
                                    + cur[0];

                int rightWalls = countWalls(walls,robotDist[i].first,range[i].second) 
                                    + cur[1];

                prev[prevDir] = max(leftWalls, rightWalls);
            }
            cur = prev;
        }

        // 0 - left, 1 - right
        return cur[0];
    }
};