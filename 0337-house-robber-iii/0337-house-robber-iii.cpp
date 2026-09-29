class Solution {
private:
    // Returns {max money if ROBBED, max money if NOT ROBBED}
    pair<int, int> dfs(TreeNode* root) {
        // Base case: a null node yields 0 money in both scenarios
        if (root == NULL) {
            return {0, 0};
        }

        // Post-order traversal: calculate answers for children first
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        // Option 1: We ROB this node. 
        // Constraint: We CANNOT rob its direct children.
        // So, we must add the "not robbed" values of the left and right children.
        int rob = root->val + left.second + right.second;

        // Option 2: We DO NOT ROB this node.
        // Freedom: We can either rob or not rob its children, whichever yields more money.
        // We take the max of the two choices for both the left and right child.
        int notRob = max(left.first, left.second) + max(right.first, right.second);

        return {rob, notRob};
    }

public:
    int rob(TreeNode* root) {
        pair<int, int> ans = dfs(root);
        
        // The final answer is the maximum of robbing or not robbing the root
        return max(ans.first, ans.second);
    }
};