/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};
        queue<Node*> q;
        Node* cur = root;
        q.push(cur);
        q.push(NULL);

        vector<vector<int>>ans;
        vector<int>curLevel;
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            if(temp == NULL){
                ans.push_back(curLevel);
                curLevel.clear();
                if(!q.empty())
                    q.push(NULL);
                continue;
            }
            curLevel.push_back(temp->val);

            for(auto v : temp->children){
                if(v != NULL)
                    q.push(v);
            }
              
        }
        return ans;

    }
};