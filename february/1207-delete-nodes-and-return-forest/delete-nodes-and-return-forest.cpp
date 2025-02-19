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
    TreeNode* solve(TreeNode* root, unordered_set<int>& s,
                    vector<TreeNode*>& result) {
        if (root == NULL)
            return NULL;
        root->left=solve(root->left, s, result);
        root->right=solve(root->right, s, result);
        if (s.count(root->val)) {
            if (root->left) {
                TreeNode* l = root->left;
                result.push_back(l);
            }
            if (root->right) {
                TreeNode* r = root->right;
                result.push_back(r);
            }

            return NULL;
        }else{
            return root;
        }
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s;
        vector<TreeNode*> result;
        for (auto& e : to_delete) {
            s.insert(e);
        }

         solve(root, s, result);
        if (!s.count(root->val)) {
            result.push_back(root);
        }

        return result;
    }
};