#include <stdlib.h> 

class RandomizedSet {
private:
    std::set<int> mySet;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool inSet = mySet.count(val);
        mySet.insert(val);
        
        return !inSet;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        return mySet.erase(val);
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        //int randNum = rand() % mySet.size();
        return *mySet.begin();
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
