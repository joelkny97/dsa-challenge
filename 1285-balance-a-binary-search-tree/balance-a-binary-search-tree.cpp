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
    TreeNode* balanceBST(TreeNode* root) {
        if (root == nullptr) return nullptr;

        TreeNode* vineHead = new TreeNode(0);
        vineHead->right = root;
        
        TreeNode* current = vineHead;

        // Create backbone by right rotations
        while (current->right != nullptr) {
            if (current->right->left != nullptr) {
                rightRotate(current, current->right);
            }
            else {
                current = current->right;
            }
        }
        // Count nodes
        int count=0;
        current = vineHead->right;
        while (current!=nullptr) {
            count+=1;
            current = current->right;
        }
        
        int m = pow(2, floor(log2(count+1))) -1;

        // Make (count - m) left rotations to partially balance the tree
        doRotations(vineHead, count-m);
        // Further perform left rotations until m<=1 to balance the BST
        while(m>1) {
            m /= 2;
            doRotations(vineHead, m);
        }

        TreeNode* res = vineHead->right;
        delete vineHead;
        return res;

    }
private:
    void rightRotate(TreeNode* parent, TreeNode* node) {
        TreeNode* temp = node->left;
        node->left = temp->right;
        temp->right = node;
        parent->right = temp;
    }

    void leftRotate(TreeNode* parent, TreeNode* node) {
        TreeNode* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        parent->right = temp;
    }

    void doRotations(TreeNode* vineHead, int count) {
        TreeNode* leftR = vineHead;
        for (int i=0; i<count; ++i) {
            TreeNode* tmp = leftR->right;
            leftRotate(leftR, tmp);
            leftR = leftR->right;
        }
    }
};