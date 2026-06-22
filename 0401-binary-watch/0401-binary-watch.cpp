class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for(int hours = 0;hours <= 11;hours++){
            for(int mins = 0;mins <= 59;mins++){
                if(__builtin_popcount(hours) + __builtin_popcount(mins) == turnedOn){ // No. of Set Bits
                    string HH = to_string(hours);
                    string MM = (mins < 10 ? "0": "") + to_string(mins);

                    ans.push_back(HH+":"+MM); 
                } 
            }
        }

        return ans;
    }
};