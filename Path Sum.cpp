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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        int sum=root->val;
        if(sum==targetSum && !root->left && !root->right) return true;
        return helper(root->left,sum,targetSum) || helper(root->right,sum,targetSum);
    }
    bool helper(TreeNode* root,int sum,int targetSum){
        if(!root) return false;
        sum+=root->val;
        if(sum==targetSum && !root->left && !root->right) return true;
        return helper(root->left,sum,targetSum) || helper(root->right,sum,targetSum);
    }
};
