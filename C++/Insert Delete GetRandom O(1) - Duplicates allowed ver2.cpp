#include <stdlib.h> 

class RandomizedCollection {
private:
    
    unordered_map<int, vector<int>> mmap;
    vector<int> elements;
    
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        mmap[val].push_back( elements.size() );
        elements.push_back(val);

        return mmap[val].size()==1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto bucket = &mmap[val];
        bool found = !bucket->empty();
        
        if (found) {
            int pos = bucket->back(); bucket->pop_back();
            int last = elements.back(); elements.pop_back();
            if(last != val){
              auto bucket2 = &mmap[last];
              bucket2->pop_back(); 
              bucket2->push_back(pos);
              
              elements[pos] = last;
            } 
        }
        
        return found;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int pos = rand() % elements.size();
        return elements[pos];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
