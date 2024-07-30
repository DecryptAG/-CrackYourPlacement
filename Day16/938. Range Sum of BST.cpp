// https://leetcode.com/problems/range-sum-of-bst/

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
    int ans = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL)
            return 0;
        int left = rangeSumBST(root->left,low,high);
        int right = rangeSumBST(root->right,low,high);
        if(root->val <=high && root->val>=low)
        {
            ans+=root->val;
        }
        return ans;
    }
};