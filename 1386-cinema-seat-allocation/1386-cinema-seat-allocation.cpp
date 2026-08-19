class Solution {
bool isAvaliable(int seat, unordered_set<int> &reservedSeat){
    return reservedSeat.find(seat) == reservedSeat.end();
}
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;

        for (auto reservedSeat : reservedSeats)
            mp[reservedSeat[0]].insert(reservedSeat[1]);

        int result = (n - mp.size()) * 2;

        for (auto it : mp) {
            int row = it.first;
            unordered_set<int> reservedSeat = it.second;

            bool groupA =
                isAvaliable(2, reservedSeat) && isAvaliable(3, reservedSeat) &&
                isAvaliable(4, reservedSeat) && isAvaliable(5, reservedSeat);
            
            bool groupB =
                isAvaliable(4, reservedSeat) && isAvaliable(5, reservedSeat) &&
                isAvaliable(6, reservedSeat) && isAvaliable(7, reservedSeat);
            
            bool groupC =
                isAvaliable(6, reservedSeat) && isAvaliable(7, reservedSeat) &&
                isAvaliable(8, reservedSeat) && isAvaliable(9, reservedSeat);
            
            if(groupA && groupC)
                result += 2;
            else if(groupA || groupB || groupC)
                result += 1;
            else 
                continue;
        }

        return result;
    }
};