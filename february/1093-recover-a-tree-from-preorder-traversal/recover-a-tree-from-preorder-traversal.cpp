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
 
    TreeNode* solve(string& traversal, int& i, int depth){
        if(i>=traversal.length()){
            return NULL;
        }
        int j = i;
        while(j<traversal.length() && traversal[j]=='-'){
            j++;
        }
        int dash = j-i;
        if(depth!=dash){
            return NULL;
        }
        i+=dash;
        int value=0;
        while(i<traversal.length() && isdigit(traversal[i])){
            value = value*10+traversal[i]-'0';
            i++;
        }
        TreeNode* root = new TreeNode(value);
        root->left = solve(traversal,i,depth+1);
        root->right = solve(traversal,i,depth+1);
        return root;

    }
    TreeNode* recoverFromPreorder(string traversal) {
        int i = 0;
        return solve(traversal,i,0);
    }
};