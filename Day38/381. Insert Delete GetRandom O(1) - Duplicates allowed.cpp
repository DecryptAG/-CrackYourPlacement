// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/

class RandomizedCollection {
public:
    unordered_map<int,set<int>> mp;
    vector<int> v;
    RandomizedCollection() {
    }
    
    bool insert(int val) {
        bool ans = mp[val].size()==0;
        mp[val].insert(v.size());
        v.push_back(val);
        return ans;
    }
    
    bool remove(int val) {
        bool ans = mp[val].size()>0;
        if(ans)
        {   
            int ind = *(mp[val].begin());
            mp[val].erase(ind);
            swap(v[v.size()-1],v[ind]);
            mp[v[ind]].insert(ind);
            mp[v[ind]].erase(v.size()-1);
            v.pop_back();
        }
        return ans;
    }
    
    int getRandom() {
        int x = v.size();
        int ind = rand()%x;
        return v[ind];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */