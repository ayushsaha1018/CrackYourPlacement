class RandomizedCollection {
public:
    vector<int> v;
    unordered_map<int, set<int>> mp;
    int ind = 0;

    RandomizedCollection() {}

    bool insert(int val) {
        v.push_back(val);
        mp[val].insert(v.size() - 1);

        if (mp[val].size() == 1)
            return true;

        return false;
    }

    bool remove(int val) {
        auto it = mp.find(val);
        if (it != mp.end()) {
            auto pos = *it->second.begin();
            it->second.erase(it->second.begin());

            v[pos] = v.back();
            mp[v.back()].insert(pos);
            mp[v.back()].erase(v.size()-1);

            v.pop_back();
            if(it -> second.size() == 0){
                mp.erase(it);
            }

            return true;
        }
        return false;
    }

    int getRandom() {
        int i = rand() % v.size();
        return v[i];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */