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

class Codec {
public:
    //rootLeftRight - preorder traversal
    void serHelper(TreeNode* root, string& ser){
        if(!root){
            ser += "N#";
            return;
        }

        ser += to_string(root->val) + '#';
        serHelper(root->left, ser);
        serHelper(root->right, ser);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ser = "";
        serHelper(root, ser);
        return ser;
    }

    TreeNode* derHelper(string& data, int& i){
        string value = "";
        while(i < data.size() && data[i] != '#'){
            value += data[i];
            i++;
        }

        i++;

        if(value == "N"){
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(value));
        node->left = derHelper(data, i);
        node->right = derHelper(data, i);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return derHelper(data, i);
    }
};
