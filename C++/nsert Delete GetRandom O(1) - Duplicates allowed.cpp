#include <stdlib.h> 

class RandomizedCollection {
private:
    unordered_multimap<int, int> map;
    vector<int> elements;
    
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        int count = map.count(val);
        map.insert(make_pair(val, elements.size()));
        elements.push_back(val);
        
        return !count;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto inSet = map.find(val);
        
        if(inSet != map.end()){
            int pos = map.find(val)->second;
            map.erase (map.find(val), ++map.find(val));
            
            int last = elements.back(); elements.pop_back();
            elements[pos] = last;
            
            for(auto findPos = map.find(last); findPos != map.end(); ++findPos){
                if(findPos->second == elements.size()){
                    map.erase( findPos, std::next(findPos));
                    map.insert( make_pair(last, pos));
                }
            }
        }
        
        return inSet != map.end();
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
