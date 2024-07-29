// https://leetcode.com/problems/flatten-nested-list-iterator/description/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> v;
    int ind = 0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        getValues(nestedList,v);
    }
    void getValues(vector<NestedInteger> &nestedList, vector<int> &v)
    {   
        int n = nestedList.size();
        for(int i=0;i<n;i++)
        {
            if(nestedList[i].isInteger())
            {   
                int x = nestedList[i].getInteger();
                cout<<x<<endl;
                v.push_back(x);
            }
            else
            {   
                getValues(nestedList[i].getList(),v);
            }
        }
    }
    int next() {
        int x = v[ind];
        ind++;
        return x;
    }
    
    bool hasNext() {
        return ind < (v.size());
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */