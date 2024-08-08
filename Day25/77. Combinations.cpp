// https://leetcode.com/problems/combinations/

class Solution {
public:
    void solve(int ind, vector<int> &ds, int k, vector<vector<int>> &ans,int n)
    {   
        if(ind>n && k!=0)
        {
            return;
        }
        if(k==0)
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(ind);
        solve(ind+1,ds,k-1,ans,n);
        ds.pop_back();
        solve(ind+1,ds,k,ans,n);
    } 
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1,ds,k,ans,n);
        return ans;
    }
};