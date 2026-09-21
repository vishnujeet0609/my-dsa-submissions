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

    void getPaths(TreeNode* root, vector<string>& paths, string cur){
            if(!root) return;

            if(root->left == nullptr && root->right == nullptr){
                cur = cur + to_string(root->val);
                paths.push_back(cur);
                return;
            }
            int val = root->val;
            getPaths(root->left, paths, cur + to_string(val) + "->");
            getPaths(root->right, paths, cur + to_string(val) + "->");

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>paths;
        string curPath = "";

        getPaths(root, paths, curPath);
        return paths;
    }
};