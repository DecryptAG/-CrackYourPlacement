// https://www.geeksforgeeks.org/problems/rat-maze-with-multiple-jumps3852/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int n;
    bool safe(int x,int y,vector<vector<int>>&m){
        return ( x>=0 && x<n && y>=0 && y<n && m[x][y]!=0); 
    }
    bool solve(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &ansMatrix)
    {
        if(i==n-1 && j==n-1)
        {
            ansMatrix[i][j] = 1;
            return true;
        }
            
       if(safe(i,j,grid) && !ansMatrix[i][j]){
            ansMatrix[i][j]=1;
            for(int x=1;x<=grid[i][j] && x<n;x++){
                if(solve(i,j+x,grid,ansMatrix)) return true;
                if(solve(i+x,j,grid,ansMatrix)) return true;
            }
            ansMatrix[i][j]=0;
            return false;
        } 
        return false;
    }
	vector<vector<int>> ShortestDistance(vector<vector<int>>&grid){
	   // Code here
	   n = grid.size();
	   vector<vector<int>> ansMatrix(n,vector<int>(n,0));
	   if(solve(0,0,grid,ansMatrix) == false)
	        return {{-1}};
	   return ansMatrix;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends