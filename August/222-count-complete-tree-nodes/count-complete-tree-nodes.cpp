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

    int getLeftExtremeHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return getLeftExtremeHeight(root->left) + 1;
    }

    int getRightExtremeHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return getRightExtremeHeight(root->right) + 1;
    }

    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int lh = getLeftExtremeHeight(root);
        int rh = getRightExtremeHeight(root);

        if(lh == rh){
            return (1<<lh )- 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};