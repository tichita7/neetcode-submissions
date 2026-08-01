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
    int maxi = INT_MIN;
    int solve(TreeNode* root){
        if(!root) return 0;

        int left = solve(root->left);
        if(left < 0) left = 0;

        int right = solve(root->right);
        if(right < 0) right = 0;

        maxi = max(maxi, root->val + left + right);

        return root->val + max(left, right);
        
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};
