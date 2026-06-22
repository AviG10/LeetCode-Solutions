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
    bool isLeaf(TreeNode* root){
        return !root->left && !root->right;
    }
    
    void addToSum(string &s, int &ans){
        int n = s.length();
        int multiplier = 1;
        int res = 0;

        for(int i = n-1;i >= 0;i--){
            if(s[i] == '1') res += multiplier;
            multiplier = multiplier * 2;  
        }
        
        ans += res;
    }

    void preorderTraversal(TreeNode* root, string &s, int &ans){
        if(isLeaf(root)){
            s += to_string(root->val);
            addToSum(s,ans);
            s.pop_back();
        }

        s += to_string(root->val);
        if(root->left != NULL) preorderTraversal(root->left,s,ans);
        if(root->right != NULL) preorderTraversal(root->right,s,ans);
        s.pop_back();
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        string s = "";
        
        preorderTraversal(root,s,ans);

        return ans;
    }
};