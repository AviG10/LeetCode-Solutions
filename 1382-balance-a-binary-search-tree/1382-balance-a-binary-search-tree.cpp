/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void inorder(TreeNode* root, vector<int> &inOrder){
        if(root == NULL) return;

        inorder(root->left,inOrder);
        inOrder.push_back(root->val);
        inorder(root->right,inOrder);
    }

    TreeNode* buildBalancedBST(int l, int r, vector<int> &inOrder){
        if(l > r) return NULL;

        int mid = l + (r-l)/2;

        TreeNode* root = new TreeNode(inOrder[mid]);
        root->left = buildBalancedBST(l,mid-1,inOrder);
        root->right = buildBalancedBST(mid+1,r,inOrder);

        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inOrder;

        inorder(root,inOrder);
        
        int l = 0, r = inOrder.size()-1;
        
        return buildBalancedBST(l,r,inOrder);
    }
};