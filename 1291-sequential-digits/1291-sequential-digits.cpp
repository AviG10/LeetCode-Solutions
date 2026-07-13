class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int l = to_string(low).length();
        int h = to_string(high).length();

        string s = "123456789";

        for (int len = l; len <= h; len++) {
            for (int start = 0; start <= 9 - len; start++) {
                
                string numStr = s.substr(start, len);
                int num = stoi(numStr);
                
                if(low <= num && num <= high){
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};