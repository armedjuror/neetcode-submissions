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
    int maxDepth(TreeNode* root) {
        int mdepth = 0;
        if (root == nullptr) return mdepth;
        mdepth++;
        mdepth += max(maxDepth(root->left), maxDepth(root->right));
        return mdepth;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)return 0;
        return max({
            maxDepth(root->left)+maxDepth(root->right),
            diameterOfBinaryTree(root->left),
            diameterOfBinaryTree(root->right)
    });
    }
};
