// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<pair<TreeNode*, pair<int,int>>> todo;
        map<int,map<int,multiset<int>>> nodes;
        todo.push({root,{0,0}});
        while(!todo.empty())
        {   
            auto it = todo.front();
            todo.pop();
            TreeNode* node = it.first;
            int x = it.second.first;
            int y = it.second.second;
            nodes[x][y].insert(node->val);
            if(node->left)
            {
                todo.push({node->left,{x-1,y+1}});
            }
            if(node->right)
            {
                todo.push({node->right,{x+1,y+1}});
            }
        }
        for(auto p: nodes)
        {   
            vector<int> col;
            for(auto q: p.second)
            {
                col.insert(col.end(),q.second.begin(),q.second.end());
                // for(auto it: q.second)
                // {
                //     col.push_back(it);
                // }
            }
            ans.push_back(col);
        }
        return ans;
    }
};