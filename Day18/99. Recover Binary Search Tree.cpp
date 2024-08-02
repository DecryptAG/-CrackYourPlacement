// https://leetcode.com/problems/recover-binary-search-tree/description/

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
    TreeNode *first, *prev,*next,*middle;
    void inorder(TreeNode* root)
    {
        if(root == NULL)
            return;
        inorder(root->left);
        if(prev!=NULL && root->val < prev->val)
        {
            if(first==NULL)
            {
                first = prev;
                middle = root;
            }
            else
            {
                next = root;
            }
        }
        
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(root==NULL)
            return;
        // prev = new TreeNode(INT_MIN);
        inorder(root);
        if(next == NULL)
            swap(first->val,middle->val);
        else
            swap(first->val,next->val);
    }
};