/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* lowestCommonAncestorHelper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestorHelper(root->left, p, q);
        TreeNode* right = lowestCommonAncestorHelper(root->right, p, q);

        if(left == NULL && right == NULL)
            return NULL;
        else if(left == NULL && right != NULL)
            return right;
        else if(left != NULL && right == NULL)
            return left;
        else
            return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lowestCommonAncestorHelper(root, p, q);
    }
};