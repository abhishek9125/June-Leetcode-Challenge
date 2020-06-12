class RandomizedSet{
    map<int,int> cache;
    vector<int> values;
    int n = 0;
public:
    /** Initialize your data structure here. */
    RandomizedSet(){
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val){
        if(cache.count(val)){
            return false;
        }
        cache[val] = n;
        values.push_back(val);
        n++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val){
        if(cache.count(val)==0){
            return false;
        }
        int index = cache[val];
        int last = values.back();
        values[index] = last;
        cache[last] = index;
        values.pop_back();
        cache.erase(val);
        n--;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return values[rand()%n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
