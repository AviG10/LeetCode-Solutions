class Solution {
private:    
    int calculateEuclidianDist(int x, int y){
        return (x * x + y * y);
    } 
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

        unordered_map<string, int> mp;
        int n1 = commands.size(), n2 = obstacles.size();

        for(int i = 0;i < n2;i++){
            mp[to_string(obstacles[i][0])+ "_" + to_string(obstacles[i][1])]++;
        }

        int idx = 0;
        pair<int,int> coordinate = {0,0};
        int ans = 0;

        for(int i = 0;i < n1;i++){
            if(commands[i] == -2){
                idx = idx-1 < 0 ? 3 : idx-1;
            }
            else if(commands[i] == -1){
                idx = idx+1 > 3 ? 0 : idx+1;
            }
            else{
                int addX = dir[idx].first;
                int addY = dir[idx].second;
                
                int curX = coordinate.first;
                int curY = coordinate.second;

                int newX = curX, newY = curY;
                for(int j = 0;j < commands[i];j++){
                    newX += addX;
                    newY += addY;

                    if(mp.find(to_string(newX)+"_"+to_string(newY)) != mp.end()) {
                        break;
                    }
                    else{
                        coordinate.first = newX;
                        coordinate.second = newY;
                    }
                }

                ans = max(ans, calculateEuclidianDist(coordinate.first, coordinate.second));
            }
        }

        return ans;
    }
};