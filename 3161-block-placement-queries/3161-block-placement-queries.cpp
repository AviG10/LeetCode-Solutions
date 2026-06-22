class SegmentTree {
private:
    vector<int> segTree;
    int n;

    void pointUpdateHelper(int idx, int val, int i, int l, int r) {
        if (l == r) {
            segTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            pointUpdateHelper(idx, val, 2 * i + 1, l, mid);
        } else {
            pointUpdateHelper(idx, val, 2 * i + 2, mid + 1, r);
        }

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

    SegmentTree(int size) {
        n = size;
        segTree.resize(4 * n, 0);
    }

    void pointUpdate(int idx, int val) {
        return pointUpdateHelper(idx, val, 0, 0, n - 1);
    }

    int rangeQuery(int left, int right) {
        return rangeQueryHelper(left, right, 0, 0, n - 1);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int maxN = 50000;
        SegmentTree segTree(maxN);

        set<int> st;
        st.insert(0);

        vector<bool> ans;

        for (auto query : queries) {
            if (query[0] == 1) {
                int x = query[1];

                auto it = st.upper_bound(x);
                int next = (it != st.end()) ? *it : -1;
                int pre = *prev(it);

                segTree.pointUpdate(x, x - pre);
                if (next != -1)
                    segTree.pointUpdate(next, next - x);

                st.insert(x);
            } else {
                int x = query[1];
                int sz = query[2];

                auto it = st.upper_bound(x);
                int pre = *prev(it);

                int maxGap = segTree.rangeQuery(0, pre);
                maxGap = max(maxGap, x - pre);

                ans.push_back(maxGap >= sz);
            }
        }

        return ans;
    }
};