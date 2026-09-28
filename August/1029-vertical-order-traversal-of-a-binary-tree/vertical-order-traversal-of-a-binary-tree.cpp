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

    void getVerticalTraversal(TreeNode* root, int level, int col, map<int, vector<pair<int,int>>>& mp){
        if(root == NULL){
            return;
        }

        mp[col].push_back({level, root->val});

        getVerticalTraversal(root->left, level+1, col-1, mp);
        getVerticalTraversal(root->right, level+1, col+1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int>>> mp;
        getVerticalTraversal(root,0, 0 ,mp);

        vector<vector<int>>ans;
        for(auto it : mp){
            sort(it.second.begin(), it.second.end());
            vector<int>res;
            for(auto v : it.second){
                res.push_back(v.second);
            }
            ans.push_back(res);
        }
        return ans;
    }
};