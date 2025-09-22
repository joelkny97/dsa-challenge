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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) return true;
        if (!root ) return false;
        if (!subRoot) return true;

        TreeNode* currentTree = root;
        TreeNode* currentSub = subRoot;

        queue<TreeNode*> q;
        // queue<TreeNode*> qSub;

        q.push(root);
        // qSub.push(subRoot);
        bool res = false;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (!curr) continue;
            if (curr->val == currentSub->val) {
                res = isSame(curr, currentSub);
                if (res) return true;
                // return isSame(curr->left, currentSub) || isSame(curr->right, currentSub);
            }
            // else {
            q.push(curr->left);
            q.push(curr->right);
            // }
        }

        return res;
        
    }
private:
    bool isSame(TreeNode* node, TreeNode* subNode) {
        if (!node && !subNode) return true;
        if (!node || !subNode) return false;

        if (node->val != subNode->val) return false;

        return isSame(node->left, subNode->left) && isSame(node->right, subNode->right);

    }
};