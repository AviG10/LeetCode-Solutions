class SegmentTree {
private:
    vector<int> segTree;
    int n;

    void build(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            segTree[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * i + 1, l, mid, nums);
        build(2 * i + 2, mid + 1, r, nums);

        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    int rangeQueryHelper(int left, int right, int i, int l, int r) {
        if (left > r || right < l)
            return 0;
        if (l >= left && r <= right)
            return segTree[i];

        int mid = l + (r - l) / 2;

        return max(rangeQueryHelper(left, right, 2 * i + 1, l, mid),
                   rangeQueryHelper(left, right, 2 * i + 2, mid + 1, r));
    }
    
public:
    SegmentTree(vector<int>&nums, int size) {
        n = size;
        segTree.resize(4 * n, 0);
        build(0, 0, n - 1, nums);
    }

    int rangeQuery(int left, int right) {
        return rangeQueryHelper(left, right, 0, 0, n - 1);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        vector<int> blockStart;
        vector<int> blockEnd;
        vector<int> blockSize;

        int n = s.length();
        int originalActiveSessions = 0;
        int idx = 0;

        while(idx < n){
            if(s[idx] == '0'){
                int start = idx;
                
                while(idx < n && s[idx] == '0') idx++;
                
                blockStart.push_back(start);
                blockEnd.push_back(idx-1);
                blockSize.push_back(idx - start);
            }
            else{
                originalActiveSessions++;
                idx++;
            }
        }

        int m = blockSize.size();

        if(m < 2)
            return vector<int>(queries.size(), originalActiveSessions);

        vector<int> pairSum(m-1);

        for(int i = 0;i < m-1; i++)
            pairSum[i] = blockSize[i] + blockSize[i+1];
        
        SegmentTree segTree(pairSum, m-1);
        vector<int> result;

        for(auto &query : queries){
            int l = query[0];
            int r = query[1];

            int lowBlockIdx = lower_bound(blockEnd.begin(), blockEnd.end(), l) - blockEnd.begin();
            int highBlockIdx = upper_bound(blockStart.begin(), blockStart.end(), r) - blockStart.begin() - 1;

            int maxPairSum = 0;

            if(lowBlockIdx < highBlockIdx){
                int firstBlockInclusionLen = blockEnd[lowBlockIdx] - max(blockStart[lowBlockIdx], l) + 1;
                int lastBlockInclusionLen = min(blockEnd[highBlockIdx], r) - blockStart[highBlockIdx] + 1;

                if(highBlockIdx - lowBlockIdx == 1){
                    maxPairSum = firstBlockInclusionLen + lastBlockInclusionLen;
                }
                else{
                    int firstPairSum = firstBlockInclusionLen + blockSize[lowBlockIdx + 1];
                    int lastPairSum = blockSize[highBlockIdx - 1] + lastBlockInclusionLen;
                    int remainingRMQPairSum = segTree.rangeQuery(lowBlockIdx + 1, highBlockIdx - 2);

                    maxPairSum = max({firstPairSum, lastPairSum, remainingRMQPairSum});
                }
            } 

            result.push_back(maxPairSum + originalActiveSessions);
        }
        
        return result;
    }
};