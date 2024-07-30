// https://leetcode.com/problems/binary-tree-paths/description/

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
    void solve(TreeNode* root, vector<string> &ans, string str)
    {
        if(root->left == NULL && root->right == NULL)
        {       
            str+=(to_string(root->val));
            ans.push_back(str);
            return;
        }
        str+=(to_string(root->val));
        str+="->";
        if(root->left)
            solve(root->left,ans,str);
        if(root->right)
            solve(root->right,ans,str);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string t = "";
        solve(root,ans,t);
        return ans;
    }
};