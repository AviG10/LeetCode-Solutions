// Counting Sorting + Greedy
// TC - O(n)
// SC - O(n)
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = 0;
        for(int &cost : costs){
            maxCost = max(maxCost, cost);
        }

        vector<int> countCoins(maxCost+1, 0);
        for(int &cost : costs){
            countCoins[cost]++;
        }
        
        int maxIceBar = 0;
        int totalCost = 0;
        
        for(int i = 0;i < countCoins.size(); i++){
            if(totalCost >= coins) break;

            if(countCoins[i] != 0){
               int coinCanbeTaken = min( countCoins[i] , (coins - totalCost) / i);
               maxIceBar += coinCanbeTaken;
               totalCost += coinCanbeTaken * i;
            }
        }

        return maxIceBar;
    }
};