/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();
            
            if(curNode == NULL)
                s += "#,";
            else
                s += to_string(curNode->val) + ",";

            if(curNode != NULL){
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }

        cout<<s<<endl;

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
            return NULL;
        
        stringstream s(data);
        string str = "";
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();

            getline(s, str, ',');
            
            if(str == "#"){
                curNode->left = NULL;
            }
            else{
                curNode->left = new TreeNode(stoi(str));
                q.push(curNode->left);
            }

            getline(s, str, ',');
            
            if(str == "#"){
                curNode->right = NULL;
            }
            else{
                curNode->right = new TreeNode(stoi(str));
                q.push(curNode->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));