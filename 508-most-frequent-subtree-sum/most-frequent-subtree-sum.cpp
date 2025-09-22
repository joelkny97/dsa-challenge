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
    vector<int> res;
    unordered_map<int, int> counts;
    int maxFreq;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        if (root == nullptr) return {};
        
        dfs(root);
        maxFreq = INT_MIN;
        for (auto& i: counts) {
            maxFreq = max(i.second, maxFreq);
        }

        for (auto& i: counts) {
            if (i.second == maxFreq) {
                res.push_back(i.first);
            }
        }

        return res;
    }

private:
    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int sum = root->val + dfs(root->left) + dfs(root->right);
        counts[sum] += 1;
        return sum;
    }
};