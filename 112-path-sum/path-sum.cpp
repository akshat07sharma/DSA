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
    bool path(TreeNode* root, int target){
        if(root->left == nullptr && root->right==nullptr){
            return root->val == target;
        }
        bool left = false;
        bool right = false;
        if(root->left){
            left = path(root->left,target-root->val);
        }
        if(root->right){
           right =  path(root->right,target-root->val);
        }
        return left || right;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return false;
        }
        return path(root,targetSum);
    }
};