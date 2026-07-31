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
    TreeNode* solve(int prest, int prend, vector<int>& preorder, int inst, int inend, vector<int>& inorder, unordered_map<int,int>& mp){
        //edge cases
        if(prest > prend || inst > inend) return NULL;

        int root = preorder[prest];
        TreeNode* node = new TreeNode(root);

        int ind = mp[root];
        int nleft = ind - inst ;

        node->left = solve(prest + 1, prest + 1 + nleft, preorder, inst, ind-1, inorder, mp);
        node->right = solve(prest + nleft + 1, prend, preorder, ind + 1, inend, inorder, mp);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int> mp; //value->index

        for(int i = 0; i<n; i++){
            mp[inorder[i]] = i;
        }

        return solve(0, n-1, preorder, 0, n-1, inorder, mp);
    }
};
