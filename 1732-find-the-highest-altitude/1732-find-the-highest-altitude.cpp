class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int maxGain = 0;
        int n = gain.size();

        for(int i = 0;i < n;i++){
            altitude += gain[i];
            maxGain = max(maxGain, altitude);
        }

        return maxGain;
    }
};