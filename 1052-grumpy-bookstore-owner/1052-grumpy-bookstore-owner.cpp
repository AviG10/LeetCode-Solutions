class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int satisfiedCust = 0, unSatisfiedCust = 0;

        for(int i = 0; i < n; i++){
            if(grumpy[i] == 0){
                satisfiedCust += customers[i];
            }
        }

        for(int i = 0; i < minutes; i++){
            unSatisfiedCust += customers[i] * grumpy[i];
        }

        int i = 0, j = minutes;
        int maxUnSatisfiedCustConverted = unSatisfiedCust;

        while(j < n){
            unSatisfiedCust += customers[j] * grumpy[j];
            unSatisfiedCust -= customers[i] * grumpy[i];
            maxUnSatisfiedCustConverted = max(maxUnSatisfiedCustConverted, unSatisfiedCust);
            i++, j++;
        }

        return satisfiedCust + maxUnSatisfiedCustConverted;
    }
};