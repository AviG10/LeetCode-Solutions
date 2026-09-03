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
    int f(TreeNode* root){
        if(root == NULL) return 0;

        int left = f(root->left);
        int right = f(root->right);

        return 1+ max(left,right);
    }
public:
    int maxDepth(TreeNode* root) {
        return f(root);
    }
};