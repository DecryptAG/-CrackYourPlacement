// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/1341658765/

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
    void solve(TreeNode* root, TreeNode* &prev)
    {
        if(root == NULL)
            return;
        solve(root->right, prev);
        solve(root->left, prev);
        if(prev)
        {
            root -> right = prev;
            root->left = NULL;
        }
        prev = root;
    }
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        solve(root, prev);
    }
};