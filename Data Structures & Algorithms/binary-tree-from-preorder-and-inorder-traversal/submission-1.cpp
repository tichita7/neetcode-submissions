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
public:
    TreeNode* solve(int prest, int prend, vector<int>& preorder, int inst, int inend, vector<int>& inorder, unordered_map<int, int>& mp){
        //edge case
        if(prest > prend || inst > inend) return NULL;

        int rootVal = preorder[prest];
        TreeNode* root = new TreeNode(rootVal);
        int index = mp[rootVal]; //locate root in inorder
        int numleft = index - inst;

        root->left = solve(prest + 1, prest + numleft, preorder, inst, index-1, inorder, mp);
        root->right = solve(prest + numleft + 1, prend, preorder, index + 1, inend, inorder, mp);

        return root; 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size(); //both same size

        unordered_map<int, int> mp; //valur->index

        for(int i = 0; i<n; i++){
            mp[inorder[i]] = i;
        }
        return solve(0, n-1, preorder, 0, n-1, inorder, mp);
    }
};
