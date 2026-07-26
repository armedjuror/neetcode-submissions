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
    void iot(TreeNode* root, vector<int>& res){
        if (root==nullptr)return;
        iot(root->left, res);
        res.push_back(root->val);
        iot(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(!st.empty() || curr != nullptr){
            while (curr != nullptr){
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            res.push_back(curr->val);

            curr = curr->right;
        }
        // iot(root, res);
        return res;
    }
};