// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        bool ltoR = true;
        q.push(root);
        while(!q.empty())
        {   
            vector<int> zigzag;
            stack<int> zig;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(ltoR)
                    {
                        zigzag.push_back(node->val);
                    }
                else
                {
                    zig.push(node->val);
                }
                if(node->left !=NULL)
                {
                    q.push(node->left);
                }
                if(node->right !=NULL)
                {
                    q.push(node->right);
                }
            }
            while(!zig.empty())
            {
                zigzag.push_back(zig.top());
                zig.pop();
            }
            ltoR = !ltoR;
            ans.push_back(zigzag);
        }
        return ans;
    }
};