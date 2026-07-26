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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q==nullptr)return p==q;
        return isSameTree(p->right, q->right) &&  isSameTree(p->left, q->left) && p->val==q->val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root==nullptr || subRoot == nullptr)return root==subRoot;
        if (isSameTree(root, subRoot)) return true;
        else return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
    }
};
