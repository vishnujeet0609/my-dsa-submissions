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
    bool isCompleteTree(TreeNode* root) {
        if(!root){
            return true;
        }
        queue<TreeNode*>que;
        bool past = false;
        que.push(root);
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            if(node==NULL){
                past=true;
                continue;
            }
            if(node && past){
                return false;
            }
            que.push(node->left);
            que.push(node->right);
        }
        return true;
    }
};