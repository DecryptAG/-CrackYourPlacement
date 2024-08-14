// https://leetcode.com/problems/maximal-rectangle/description/

class Solution {
public:
    int maxAreaHist(vector<int> &heights)
    {
        int n = heights.size();
        stack<pair<int,int>> s;
        vector<int> left;
        vector<int> right;
        int pseudoIndex = -1;
        for(int i=0;i<n;i++)
        {
            if(s.size()==0)
            {
                left.push_back(pseudoIndex);
            }
            else if(s.size()>0 && s.top().first<heights[i])
            {
                left.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first>=heights[i])
            {
                while(s.size()>0 && s.top().first>=heights[i])
                {
                    s.pop();
                }
                if(s.size()>0)
                {
                    left.push_back(s.top().second);
                }
                else
                {
                    left.push_back(pseudoIndex);
                }
            }
            s.push({heights[i],i});
        }
        stack<pair<int,int>> st;
        pseudoIndex = n;
        for(int i=n-1;i>=0;i--)
        {
            if(st.size()==0)
            {
                right.push_back(pseudoIndex);
            }
            else if(st.size()>0 && st.top().first<heights[i])
            {
                right.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first>=heights[i])
            {
                while(st.size()>0 && st.top().first>=heights[i])
                {
                    st.pop();
                }
                if(st.size()>0)
                {
                    right.push_back(st.top().second);
                }
                else
                {
                    right.push_back(pseudoIndex);
                }
            }
            st.push({heights[i],i});
        }
        // for(int i=0;i<n;i++)
        //     cout<<right[i]<<" ";
        reverse(right.begin(),right.end());
        
        int maxA=0;
        for(int i = 0;i<n;i++)
        {
            maxA = max(maxA, (right[i]-left[i]-1)*heights[i]);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(); 
        int m = matrix[0].size();
        vector<int> v;

        for(int i=0;i<m;i++)
        {
            v.push_back(matrix[0][i] - '0');
        }

        int mx = maxAreaHist(v);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == '0')
                    v[j]= 0;
                else
                    v[j] = v[j] + (matrix[i][j]- '0');
            }
            mx = max(mx, maxAreaHist(v));
        }
        return mx;
    }
};