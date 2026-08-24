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
    TreeNode* solve(int prest, int prend, vector<int>& preorder, int inst, int inend, vector<int>& inorder, unordered_map<int, int>& mp ){
        //base case
        if(prest >= prend || inst >= inend) return NULL;

        int rootval = preorder[prest];
        TreeNode* node = new TreeNode(rootval);

        int ind = mp[rootval]; //index of the rootval in inorder
        int lefty = ind - inst;

        node->left = solve(prest+1, prest + lefty +1, preorder, inst, ind, inorder, mp);
        node->right = solve(prest+lefty+1, prend, preorder, ind+1, inend, inorder, mp);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        int n = preorder.size();

        for(int i = 0; i< n; i++){
            mp[inorder[i]] = i;
        }

        return solve(0, n, preorder, 0, n, inorder, mp);
    }
};
