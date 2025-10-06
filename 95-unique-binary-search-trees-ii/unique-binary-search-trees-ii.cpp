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
        // memoization if current range is already computed, return that subtree
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

        // generate recursively for a given range of values its left and right subtree for a particular rootVal value
        for (int rootVal = start; rootVal<= end; rootVal++) {
            // In BST root > all nodes in left subtree and root < all nodes in right subtree
            // right trees are built from start to rootval -1 
            // left trees are built from rootval + 1 to end
            vector<TreeNode*> leftSubtrees = buildTrees(start, rootVal-1);
            vector<TreeNode*> rightSubtrees = buildTrees(rootVal+1, end);

            // connect all nodes of left and right subtree accordingly
            for (TreeNode* leftTree: leftSubtrees) {
                for (TreeNode* rightTree: rightSubtrees) {
                    // create root node
                    TreeNode* root = new TreeNode(rootVal);
                    // attach its left subtree
                    root->left = leftTree;
                    // attach its right subtree
                    root->right = rightTree;
                    // add this root node to the list of trees
                    trees.push_back(root);
                }
            }
        }
        // store this list of trees for a particular range to be reused
        memo[key] = trees;
        return trees;
        
    }
};