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
    int rangeSumBST(TreeNode* root, int low, int high) {

        if (!root) return 0;

        int currentVal = (root->val >= low && root->val <= high) ? root->val : 0;
        
        int leftSum = rangeSumBST(root->left, low, high);
        int rightSum = rangeSumBST(root->right, low, high);
        
        return currentVal + leftSum + rightSum;
    }

private:
    void dfs(TreeNode* root, int& runningSum, int low, int high) {

        if (!root) return;

        if(root->val >= low && root->val <= high){
            runningSum += root->val;
        }

        
        if (low < root->val) {
            if (root->left) dfs(root->left, runningSum, low, high);
        }
        else {
            if (root->right) dfs(root->right, runningSum, low, high);
        }
        if (high > root->val) {
            if (root->right) dfs(root->right, runningSum, low, high);
        }
        else {
            if (root->left) dfs(root->left, runningSum, low, high);
        }


    }
};