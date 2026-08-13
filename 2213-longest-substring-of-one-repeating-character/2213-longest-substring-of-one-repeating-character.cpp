struct Node {
    int prefixLen = 0;
    int suffixLen = 0;
    int maxRepeatingCharLen = 0;
    int len = 0;
    char leftChar;
    char rightChar;
};

class SegmentTree{
private:   
    int n;
    vector<Node> segTree; 

    void build(int i, int l, int r, string &s){
        if(l == r){
            segTree[i] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * i + 1, l, mid, s);
        build(2 * i + 2, mid + 1, r, s);

        segTree[i] = merge(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    void pointUpdateHelper(int i, int l, int r, int pos, char ch){
        if(l == r){
            segTree[i] = {1, 1, 1, 1, ch, ch};
            return;
        }

        int mid = l + (r - l) /2;

        if(pos <= mid)
            pointUpdateHelper(2 * i + 1, l, mid, pos, ch);
        else 
            pointUpdateHelper(2 * i + 2, mid + 1, r, pos, ch);
        
        segTree[i] = merge(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    Node merge(Node &left, Node &right){
        Node node;

        node.leftChar = left.leftChar;
        node.rightChar = right.rightChar;
        node.len = left.len + right.len;

        node.prefixLen = left.prefixLen;
        if(left.prefixLen == left.len && left.rightChar == right.leftChar){
            node.prefixLen = left.prefixLen + right.prefixLen;
        }

        node.suffixLen = right.suffixLen;
        if(right.suffixLen == right.len && left.rightChar == right.leftChar){
            node.suffixLen = left.suffixLen + right.suffixLen;
        }

        node.maxRepeatingCharLen = max(left.maxRepeatingCharLen, right.maxRepeatingCharLen);
        if(left.rightChar == right.leftChar){
            node.maxRepeatingCharLen = max(node.maxRepeatingCharLen, left.suffixLen + right.prefixLen);
        }

        return node;
    }
public:
    SegmentTree(string &s){
        n = s.length();
        segTree.resize(4*n);
        
        build(0, 0, n-1, s);
    }

    void pointUpdate(int i, int l, int r, int pos, char ch){
        return pointUpdateHelper(i, l, r, pos, ch);
    }

    int rangeQuery(){
        return segTree[0].maxRepeatingCharLen;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree segTree(s);

        int n = s.length();
        int k = queryIndices.size();
        vector<int> result(k);

        for(int i = 0; i < k; i++){
            int pos = queryIndices[i];
            char ch = queryCharacters[i];

            segTree.pointUpdate(0, 0, n-1, pos, ch);
            result[i] = segTree.rangeQuery();
        }

        return result;
    }
};