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
    
    unordered_map<string, vector<TreeNode*>> memo;
    vector<TreeNode*> generateTrees(int n) {
        
        if (n==0) return vector<TreeNode*> ();

        return buildTrees(1, n);
    }
private:

    vector<TreeNode*> buildTrees(int start, int end) {
        // memoization
        string key = to_string(start)+"-"+to_string(end);   
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // base case
        vector<TreeNode*> trees;
        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        for (int rootVal = start; rootVal<= end; rootVal++) {
            vector<TreeNode*> leftSubtrees = buildTrees(start, rootVal-1);
            vector<TreeNode*> rightSubtrees = buildTrees(rootVal+1, end);

            for (TreeNode* leftTree: leftSubtrees) {
                for (TreeNode* rightTree: rightSubtrees) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = leftTree;
                    root->right = rightTree;
                    trees.push_back(root);
                }
            }
        }

        memo[key] = trees;
        return trees;
        
    }
};