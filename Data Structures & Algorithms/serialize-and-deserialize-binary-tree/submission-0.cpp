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
    void serHelper(TreeNode* root, string& ser){
        if(!root) {
            ser += "N#";
            return;
        }

        ser += to_string(root->val) + "#";

        serHelper(root->left, ser);
        serHelper(root->right, ser);
    }

    TreeNode* derHelper(string& data, int& i){
        string value = "";

        while(i < data.size() && data[i] != '#'){
            value += data[i];
            i++;
        }
        //we r on '#', so skip it
        i++;
        
        if(value == "N") return NULL;
        
        TreeNode* root = new TreeNode(stoi(value));
        root->left = derHelper(data, i);
        root->right = derHelper(data, i);
        
        return root;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ser = "";
        serHelper(root, ser);
        cout << ser;
        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return derHelper(data, i);
    }
};
