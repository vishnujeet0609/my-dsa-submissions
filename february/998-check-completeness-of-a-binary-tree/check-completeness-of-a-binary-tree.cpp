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
    int countTotalNodes(TreeNode* root){
        if(!root) return 0;
        return 1 + countTotalNodes(root->left) + countTotalNodes(root->right);
    }

    bool check(TreeNode* root,int i,int &cnt){
       if(!root) return true;
        
        if(cnt<i) return false;
       
        
        return check(root->left,2 * i,cnt) && check(root->right,2*i +1,cnt);;
        
    }
    bool isCompleteTree(TreeNode* root) {
        if(!root){
            return true;
        }
        int i = 1;
        int cnt =countTotalNodes(root);
        check(root,i,cnt);
       
        return check(root,i,cnt);
    }
};