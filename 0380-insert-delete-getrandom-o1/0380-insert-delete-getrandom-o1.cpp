class RandomizedSet {
    vector<int> v;
    unordered_map<int, int> dict;
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (dict.find(val) != dict.end())
            return false;
        v.push_back(val);
        dict[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        auto it = dict.find(val);
        if (it == dict.end())
            return false;
        
        v[it->second] = v.back(); v.pop_back();
        dict[v[it->second]] = it->second;
        dict.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */