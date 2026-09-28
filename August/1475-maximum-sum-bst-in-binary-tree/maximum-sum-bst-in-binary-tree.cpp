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


class Info{
public:
    int isBST;
    int sum;
    int mini;
    int maxi;

    Info(){
        isBST = 1;
        sum = 0;
        mini = INT_MAX;
        maxi = INT_MIN;
    }

};
class Solution {
public:

    Info* solve(TreeNode* root, int& maxSum){
        if(root == NULL){
            return new Info();
        }

        Info* leftInfo = solve(root->left, maxSum);
        Info* rightInfo = solve(root->right, maxSum);

        if(leftInfo->isBST && leftInfo->maxi < root->val && rightInfo->isBST && rightInfo->mini > root->val){
            Info* info = new Info();

            info->sum = leftInfo->sum + rightInfo->sum + root->val;
            info->mini = min(leftInfo->mini, root->val);
            info->maxi = max(rightInfo->maxi, root->val);

            maxSum = max(maxSum, info->sum);
            return info;
        } else{
            leftInfo->isBST = 0;
            return leftInfo;
        }
        return NULL;
    }

    int maxSumBST(TreeNode* root) {
        int maxSum = 0;

        solve(root, maxSum);

        return maxSum;

    }
};