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
    void ser(TreeNode* root, string& s1){
        if(!root){
            s1 += "N#";
            return; //important to return after null
        }

        s1 += to_string(root->val) + '#';

        ser(root->left, s1);
        ser(root->right, s1);
    }

    TreeNode* der(int& i, string& data){
        string val = "";
        while(i < data.size() && data[i] != '#'){
            val += data[i];
            i++;
        }

        i++; //important to move forward next to '#

        if(val == "N"){
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(val));

        root->left = der(i, data);
        root->right = der(i, data);

        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s1 = "";
        ser(root, s1);
        return s1;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return der(i, data);
    }
};
