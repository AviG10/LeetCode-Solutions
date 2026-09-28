/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int solve(TreeNode* root, bool canRob,
              unordered_map<TreeNode*, vector<int>>& mp) {
        if (root == NULL)
            return 0;
        
        if(!mp.count(root))
            mp[root] = {-1, -1};

        if (mp[root][canRob] != -1)
            return mp[root][canRob];

        int notTake =
            solve(root->left, true, mp) + solve(root->right, true, mp);

        int take = INT_MIN;
        if (canRob)
            take = root->val + solve(root->left, false, mp) +
                   solve(root->right, false, mp);

        return mp[root][canRob] = max(notTake, take);
    }

public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, vector<int>> mp;

        return solve(root, true, mp);
    }
};