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
    void inorder(TreeNode* root,int k,int &kth,int &counter){
        if(root == NULL || counter >= k){
            return;
        }
        inorder(root->left,k,kth,counter);
        counter++;
        if(counter == k){
            kth = root->val;
        }
        inorder(root->right,k,kth,counter);
    }
    int kthSmallest(TreeNode* root, int k) {
        int kth = 0;
        int counter = 0;
        inorder(root,k,kth,counter);
        return kth;
    }
};