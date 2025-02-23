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
    int n;
    TreeNode* solve(int preStart,int postStart,int preEnd,vector<int>& preorder, vector<int>&postorder){
        if(preStart>preEnd){
            return NULL;
        }
         TreeNode* root = new TreeNode(preorder[preStart]);
        if(preStart==preEnd){
            return root;
        }
        int nextNode = preorder[preStart+1];
        int j = postStart;
        while(j<n && postorder[j]!=nextNode){
            j++;
        }
    int subtreeLen = j-postStart+1;
    root->left = solve(preStart+1,postStart,preStart+subtreeLen,preorder,postorder);
    root->right = solve(preStart+subtreeLen+1,j+1,preEnd,preorder,postorder);
    return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        n = preorder.size();
        return solve(0,0,n-1,preorder,postorder);
    }
};