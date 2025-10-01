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
    int moves;
    int distributeCoins(TreeNode* root) {
        moves=0;
        dfs(root);
        return moves;
    }

private:
int dfs(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }

        int extra = root->val-1;

        extra += dfs(root->left);
        extra += dfs(root->right);

        moves += abs(extra);
        return extra;
    }
};