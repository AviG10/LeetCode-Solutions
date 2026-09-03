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
    void solve(TreeNode* root, int targetSum, vector<vector<int>> &result, vector<int> &path){
        if(root == NULL)
            return;
        
        path.push_back(root->val);
        targetSum -= root->val;

        if(root->left == NULL && root->right == NULL && targetSum == 0)
            result.push_back(path);

        solve(root->left, targetSum, result, path);
        solve(root->right, targetSum, result, path);
        
        path.pop_back();
        targetSum += root->val;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        
        solve(root, targetSum, result, path);

        return result;
    }
};