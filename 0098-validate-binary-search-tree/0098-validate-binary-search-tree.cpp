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
    bool isValidBST(TreeNode* root) {
        return isvalid(root,LONG_MIN,LONG_MAX);
    }
    bool isvalid(TreeNode* root,long minValue,long maxValue){
        if(root == NULL)return true;
        if(root->val >= maxValue || root->val <= minValue)return false;
        return isvalid(root->left,minValue,root->val)
            &&isvalid(root->right,root->val,maxValue);
    }
};