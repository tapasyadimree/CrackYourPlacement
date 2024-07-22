class RandomizedCollection {
public:
    unordered_map<int, set<int>> mpp;
    vector<int> v;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        v.push_back(val);
        mpp[val].insert(v.size()-1);

        if(mpp[val].size() == 1) return true;
        return false;
    }
    
    bool remove(int val) {
        auto it = mpp.find(val);
        if(it != mpp.end()){
            auto pos = *it->second.begin();
            it->second.erase(it->second.begin());

            v[pos] = v.back();
            mpp[v.back()].insert(pos);
            mpp[v.back()].erase(v.size()-1);

            v.pop_back();

            if(it->second.size() == 0) mpp.erase(it);

            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */