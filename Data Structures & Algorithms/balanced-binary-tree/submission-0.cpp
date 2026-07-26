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
    pair<bool, int> check(TreeNode* root){
        if (root == nullptr) return {true, 0};
        // else if (root->left != nullptr){
        //     pair<bool, int> r = check(root->left);
        //     if (r.first && r.second <= 1) return {true, 1+r.second};
        // } else if (root->right != nullptr){
        //     pair<bool, int> r = check(root->right);
        //     if (r.first && r.second <= 1) return {true, 1+r.second};
        // }
        else{
            pair<bool, int> r = check(root->right);
            pair<bool, int> l = check(root->left);
            if (r.first && l.first && abs(r.second-l.second)<=1)return {true, 1+max(r.second, l.second)};
            else return {false, 1+max(r.second, l.second)};
        }

    }

    bool isBalanced(TreeNode* root) {
       pair<bool, int> res = check(root);
       return res.first;
    }
};
