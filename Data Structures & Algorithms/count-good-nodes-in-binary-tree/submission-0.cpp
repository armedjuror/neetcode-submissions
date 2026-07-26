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
    int preOT(TreeNode* root, int gip){
        int gn = 0;
        if (root == nullptr)return gn;
        if (root->val >= gip) {
            gip = root->val;
            gn++;
        }
        gn += preOT(root->left, gip);
        gn += preOT(root->right, gip);
        return gn;
    }

    int goodNodes(TreeNode* root) {
        return preOT(root, INT_MIN);
    }
};
