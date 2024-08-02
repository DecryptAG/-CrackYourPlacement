// https://leetcode.com/problems/path-sum-iii/description/

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
    unordered_map<long long,int> mp;
    int ans = 0;
    void count(TreeNode* root, long long currSum, int target)
    {
        if(root == NULL)
            return;
        currSum+=root->val;
        ans+=mp[currSum - target];
        mp[currSum]++;
        if(root->left)
            count(root->left,currSum, target);
        if(root->right)
            count(root->right,currSum, target);
        mp[currSum]--;
        // currSum-=root->val;
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0ll] =1;
        count(root,0,targetSum);
        return ans;
    }
};