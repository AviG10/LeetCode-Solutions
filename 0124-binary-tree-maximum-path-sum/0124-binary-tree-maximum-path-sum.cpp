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
    int maxPathSumHelper(TreeNode* root, int &result){
        if(root == NULL)
            return 0;

        int leftMaxPathSum = max(0, maxPathSumHelper(root->left, result));
        int rightMaxPathSum = max(0, maxPathSumHelper(root->right, result));

        result = max(result, root->val + leftMaxPathSum + rightMaxPathSum);

        return max(leftMaxPathSum, rightMaxPathSum) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;

        maxPathSumHelper(root, result);
        
        return result;
    }
};