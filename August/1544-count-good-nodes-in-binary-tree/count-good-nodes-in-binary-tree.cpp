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
    int cnt = 0;

    void solve(TreeNode* root, int curMax){
        if(root == NULL) return;

        if(root->val >= curMax){
            cnt++;
            curMax = root->val;
        }

        solve(root->left, curMax);
        solve(root->right, curMax);
    }

    int goodNodes(TreeNode* root) {
        solve(root, root->val);
        return cnt;
    }
};