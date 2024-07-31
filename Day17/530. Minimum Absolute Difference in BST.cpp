// https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

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
    int ans = INT_MAX;
    void solve(TreeNode* root, int &prev)
    {
        if(root == NULL)
            return;
        // cout<<prev<<" ";
        solve(root->left,prev);
        // cout<<prev<<" ";
        if(prev!=-1)
            ans = min(abs(root->val - prev), ans);
        prev = root->val;
        // cout<<prev<<endl;
        solve(root->right,prev);
    }
    int getMinimumDifference(TreeNode* root) {
        int pre=-1;
        solve(root,pre);
        return ans;
    }
};