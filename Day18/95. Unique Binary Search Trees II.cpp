// https://leetcode.com/problems/unique-binary-search-trees-ii/description/

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
    map<pair<int,int>, vector<TreeNode*>> mp;
    vector<TreeNode*> solve(int start, int end)
    {
        if(start>end)
        {
            return {NULL};
        }
        if(start == end)
        {
            TreeNode* node = new TreeNode(start);
            return mp[{start,end}] = {node};
        }
        if(mp.find({start,end})!= mp.end())
            return mp[{start,end}];
        vector<TreeNode*> result;
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> left = solve(start,i-1);
            vector<TreeNode*> right = solve(i+1,end);
            for(auto l: left)
            {
                for(auto r : right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
        return mp[{start,end}] = result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};