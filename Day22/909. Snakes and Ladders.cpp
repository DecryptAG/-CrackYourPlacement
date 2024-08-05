// https://leetcode.com/problems/snakes-and-ladders/description/

class Solution {
public:
    pair<int,int> getPair(int val,vector<vector<int>> &board)
    {   
        int n = board.size();
        int row = (val-1)/n;
        int col = (val-1)%n;
        row = (n-1) - row;
        if((n%2==0 && row%2==0) || (n%2==1 && row%2==1))
        {
            col= (n-1)-col;
        }
        return {row,col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int start = 1;
        queue<pair<int,int>> q;
        q.push({start,0});
        vector<int> vis(n*n+1,0);
        while(!q.empty())
        {   
            int size = q.size();
            while(size--)
            {
                int pos = q.front().first;
                int a = q.front().second;
                q.pop();
                if(pos == n*n)
                    return a;
                for(int i=1;i<=6;i++)
                {
                    int next = pos + i;
                    if(next<= n*n && !vis[next])
                    {   
                        vis[next] = 1;
                        pair<int,int> nx = getPair(next,board);
                        // cout<<next<<" "<<nx.first<<" "<<nx.second<<endl;
                        if(board[nx.first][nx.second]!=-1)
                        {
                            next = board[nx.first][nx.second];
                            nx = getPair(next,board);
                        }
                        q.push({next,a+1});
                    }
                    
                }
            }
            
        }
        return -1;
    }
};