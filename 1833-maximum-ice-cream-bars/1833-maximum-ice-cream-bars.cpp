// Sorting + Greedy
// TC - O(n logn)
// SC - O(1)
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));
        
        int maxIceBar = 0;
        int totalCost = 0;
        
        for(int &cost : costs){
            if(totalCost + cost <= coins){
                totalCost += cost;
                maxIceBar++;
            }
            else break;
        }

        return maxIceBar;
    }
};