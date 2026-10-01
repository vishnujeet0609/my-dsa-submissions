/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* prev = NULL;

    void flatten(TreeNode* root) {
        if(root == NULL) return;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if(prev!=NULL){
            prev->right = root;
        }

        root->left = NULL;
        prev = root;

        flatten(left);
        flatten(right);
    }
};