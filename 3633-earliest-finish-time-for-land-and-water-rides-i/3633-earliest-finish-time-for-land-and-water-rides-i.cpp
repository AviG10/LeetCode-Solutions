class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int land_water = INT_MAX, water_land = INT_MAX;
        int land = INT_MAX, water = INT_MAX;
        int m = landStartTime.size(), n = waterStartTime.size();

        for(int i = 0;i < m;i++){
            land = min(land,landStartTime[i] + landDuration[i]);
        }

        for(int i = 0;i < n;i++){
            if(land >= waterStartTime[i]) land_water = min(land_water, land + waterDuration[i]);
            else land_water = min(land_water, waterStartTime[i] + waterDuration[i]);

            water = min(water, waterStartTime[i] + waterDuration[i]);
        }

        for(int i = 0;i < m;i++){
            if(water >= landStartTime[i]) water_land = min(water_land, water + landDuration[i]);
            else water_land = min(water_land, landStartTime[i] + landDuration[i]);
        }

        return min(land_water, water_land);
    }
};