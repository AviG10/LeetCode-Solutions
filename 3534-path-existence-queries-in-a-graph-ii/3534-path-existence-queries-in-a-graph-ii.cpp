class Solution {
private: 
    int LowerBound(vector<pair<int, int>> &arr, int target){
        int n = arr.size();
        int l = 0;
        int r = n-1;
        int result = -1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(arr[mid].first <= target){
                result = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        return result;
    }
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        vector<int> originalIdxMapping(n, 0);

        for (int i = 0; i < n; i++) {
            int idx = arr[i].second;
            originalIdxMapping[idx] = i;
        }

        int row = n;
        int col = log2(n) + 1;
        vector<vector<int>> ancestorTable(row, vector<int>(col, 0));

        for(int node = 0; node < n; node++){
            ancestorTable[node][0] = LowerBound(arr, arr[node].first + maxDiff);
        }

        for(int j = 1; j < col; j++){
            for(int node = 0; node < n; node++){
                ancestorTable[node][j] = ancestorTable[ancestorTable[node][j-1]][j-1];
            }
        }

        vector<int> result;

        for(auto &query : queries){
            int u = query[0];
            int v = query[1];

            int a = originalIdxMapping[u];
            int b = originalIdxMapping[v];

            if(a == b){
                result.push_back(0);
                continue;
            }
            
            if(a > b) 
                swap(a, b);
            
            int cur = a;
            int jumps = 0;

            for(int j = col - 1; j >= 0; j--){
                if(ancestorTable[cur][j] < b){
                    cur = ancestorTable[cur][j];
                    jumps += (1 << j);
                }
            }

            if(ancestorTable[cur][0] >= b)
                result.push_back(jumps + 1);
            else 
                result.push_back(-1);
        }

        return result;
    }
};