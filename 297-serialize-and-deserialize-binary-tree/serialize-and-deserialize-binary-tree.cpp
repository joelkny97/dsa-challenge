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
    int idx=0;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string res="";
        dfsSerialize(root, res);
        res = res.substr(0,res.size()-1);
        // cout<<res;
        return res;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data=="") return nullptr;
        
        vector<string> splitArr;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            splitArr.push_back(token);
        }
        // for (auto &it: splitArr){
        //     cout<<it<<" ";
        // }
        int idx=0;
        return dfsDeserialize(splitArr);
    }
private:
    void dfsSerialize(TreeNode* root, string& s) {
        if (!root){
            s += "#,";
            return;
        }

        s+= to_string(root->val)+",";
        dfsSerialize(root->left, s);
        dfsSerialize(root->right, s);
    }

    TreeNode* dfsDeserialize(vector<string>& treeArr) {
        if (treeArr[idx] == "#"){
            idx++;
            return nullptr;
        } 

        TreeNode* newRoot = new TreeNode(stoi(treeArr[idx]));
        idx++;
        newRoot->left = dfsDeserialize(treeArr);
        newRoot->right = dfsDeserialize(treeArr);

        return newRoot;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));