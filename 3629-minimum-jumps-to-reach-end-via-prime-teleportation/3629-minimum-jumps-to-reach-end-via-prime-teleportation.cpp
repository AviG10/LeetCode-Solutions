class Solution {
private:
    void buildSieve(int &n, vector<bool> &isPrime){
        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2; i*i <= n;i++){
            if(isPrime[i] == true){
                for(int j = 2; i*j <= n;j++){
                    isPrime[i*j] = false;
                }
            }
        }
    }
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;
        int maxEle = 0;

        for(int i = 0;i < n;i++){
            mp[nums[i]].push_back(i);
            maxEle = max(maxEle,nums[i]);
        }

        vector<bool> isPrime(maxEle+1,true);
        buildSieve(maxEle,isPrime);

        queue<int> q;
        unordered_set<int> st;
        vector<bool> vis(n,false);
        int steps = 0;

        q.push(0);
        vis[0] = true;

        while(!q.empty()){
            int sz = q.size();

            while(sz){
                int i = q.front();
                q.pop();
                sz--;

                if(i == n-1) return steps;

                if(i-1 >= 0 && !vis[i-1]){
                    q.push(i-1);
                    vis[i-1] = true;
                }

                if(i+1 < n && !vis[i+1]){
                    q.push(i+1);
                    vis[i+1] = true;
                }

                if(!isPrime[nums[i]] || st.count(nums[i])) continue;

                for(int multiple = nums[i];multiple <= maxEle; multiple += nums[i]){
                    if(!mp.contains(multiple)) continue;

                    for(auto it: mp[multiple]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it] = true;
                        }
                    }
                }

                st.insert(nums[i]);  
            }

            steps++;
        }

        return steps;
    }
};