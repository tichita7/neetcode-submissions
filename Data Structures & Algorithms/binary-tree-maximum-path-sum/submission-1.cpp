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
        if(left < 0) left = 0; //we wont consider negative values

        int right = solve(root->right);
        if(right < 0) right = 0; //same as above

        maxi = max(maxi, root->val + left + right); //update the max as one subtree's sum

        return root->val + max(left, right); //but moving upward, take the max of left and right
         
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};
