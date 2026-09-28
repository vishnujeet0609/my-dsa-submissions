/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void encode(TreeNode* root, string& s){
        if(root == NULL){
            s += "*";
            return;
        }

        s += to_string(root->val) + ",";

        encode(root->left, s);
        encode(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        encode(root, s);
        return s;
    }

    TreeNode* decode(string& data){
        if(data.size() == 0) return NULL;

        if(data[0] == '*'){
            data = data.substr(1);
            return NULL;
        }

        int pos = 0;
        string num = "";
        while(data[pos] != ','){
            num.push_back(data[pos++]);
        }

        TreeNode* node = new TreeNode(stoi(num));

        data = data.substr(pos+1);
        node->left = decode(data);
        node->right = decode(data);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() <= 1) return NULL;
        return decode(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));