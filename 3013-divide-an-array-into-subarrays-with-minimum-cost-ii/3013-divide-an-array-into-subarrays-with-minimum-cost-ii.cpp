// time complexity - O(nlogn)
// space complexity - O(n)
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        // Minimum Possible sum for each window of length (dist+1)
        long long cur = nums[0];

        // Small multiset contains smallest (k-1) elements in any window of (dist+1)
        // Remaining multiset contains remaining elements in any window of (dist+1)
        multiset<int> small, remaining;

        //first window
        for(int i = 1;i <= dist+1;i++){ // O(dist*log(dist))
            cur += nums[i];
            small.insert(nums[i]);
        }

        //Balancing both multiset for first Window so that smallest k-1 elements in Current Window stored in Small Multiset
        while(small.size() > k-1){ // O(dist*log(dist))
            remaining.insert(*small.rbegin());
            cur -= *small.rbegin();
            small.erase(small.find(*small.rbegin()));
        }

        // Minimum Cost of all possible choices which satisfies the conditions given in question
        long long ans = cur; 

        // Sliding the Window
        for(int i = dist+2;i < n;i++){ //O(nlogn)
            //Removal of first element of previous Window
            if(small.find(nums[i-dist-1]) != small.end()){
                cur -= nums[i-dist-1];
                small.erase(small.find(nums[i-dist-1]));
            } 
            else{
                remaining.erase(remaining.find(nums[i-dist-1]));
            }

            //Insertion of new element for current Window
            if(nums[i] < *small.rbegin()){
                small.insert(nums[i]);
                cur += nums[i];
            }
            else{
                remaining.insert(nums[i]);
            }

            //Balancing both multiset for current Window so that smallest k-1 elements in Current Window stored in Small Multiset
            while(small.size() > k-1){
                remaining.insert(*small.rbegin());
                cur -= *small.rbegin();
                small.erase(small.find(*small.rbegin()));        
            }
            while(small.size() < k-1){
                small.insert(*remaining.begin());
                cur += *remaining.begin();
                remaining.erase(remaining.find(*remaining.begin()));
            }

            ans = min(ans,cur);
        }

        return ans;
    }
};