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
class FindElements {
public:
    unordered_set<int>st;
    void Bfs(TreeNode* root, int x){
        queue<TreeNode*> que;
        root->val = x;
        que.push(root);
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            st.insert(temp->val);
            if(temp->left){
                temp->left->val = 2*temp->val+1;
                que.push(temp->left);
            }
              if(temp->right){
                temp->right->val = 2*temp->val+2;
                que.push(temp->right);
            }
        }
    
    }
    FindElements(TreeNode* root) {
        st.clear();
        Bfs(root,0);
    }
    
    bool find(int target) {
        if(st.count(target)){
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */