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

    TreeNode* getBST(vector<int>& nums, int lo, int hi){
        if(lo>hi) return nullptr;

        int mid = lo + (hi-lo)/2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = getBST(nums, lo, mid-1);
        root->right = getBST(nums, mid+1, hi);

        return root;


    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        int lo = 0;
        int hi = nums.size() - 1;

        TreeNode* root = getBST(nums, lo, hi);
        return root;
    }
};