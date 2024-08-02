// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp;
    void getParents(TreeNode* root)
    {
        if(root == NULL)
            return;
        if(root->left)
            mp[root->left] = root;
        if(root->right)
            mp[root->right] = root;
        getParents(root->left);
        getParents(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0)
            return {target->val};
        getParents(root);
        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        unordered_map<TreeNode*,int> vis;
        int flag = 0;
        while(!q.empty())
        {   
            int size = q.size();
            for(int i =0;i<size;i++)
            {
                TreeNode* node = q.front().first;
                int d = q.front().second;
                vis[node] = 1;
                q.pop();
                if(d == k-1)
                    flag = 1;
                if(mp.find(node)!=mp.end() && vis[mp[node]] == 0)
                {
                    q.push({mp[node],d+1});
                }
                if(node->left && vis[node->left] == 0)
                {
                    q.push({node->left,d+1});
                }
                if(node->right && vis[node->right] == 0)
                {
                    q.push({node->right,d+1});
                }
            }
            if(flag)
                break;
        }
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* node = q.front().first;
            q.pop();
            int val = node->val;
            ans.push_back(val);
        }
        return ans;
    }
};