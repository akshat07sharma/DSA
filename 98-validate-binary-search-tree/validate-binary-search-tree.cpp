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
    bool hai(TreeNode* root,long long mini,long long maxi){
        if(root == nullptr) return true;
        if(root->val >= maxi || root->val <=mini) return false;

        
        bool left = false;
        bool right = false;

        left = hai(root->left,mini,root->val);
        right = hai(root->right,root->val,maxi);

        return left&& right;

       
        
    }

    bool isValidBST(TreeNode* root) {
        return hai(root,LLONG_MIN, LLONG_MAX);
    }
};