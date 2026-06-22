class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        vector<int> targetInd;

        for(int i = 0;i < n;i++){
            if(words[i] == target){
                targetInd.push_back(i);
            }
        }

        int ans = INT_MAX;

        for(int i = 0;i < targetInd.size();i++){
            if(targetInd[i] > startIndex){
                ans = min(ans,min(targetInd[i]-startIndex, n-targetInd[i]+startIndex));
            }
            else{
                ans = min(ans,min(startIndex-targetInd[i], targetInd[i]+n-startIndex));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};