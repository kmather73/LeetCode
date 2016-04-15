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
    std::vector<int> list;
    NestedIterator(vector<NestedInteger> &nestedList) {
        flattenList( nestedList );
    }

    int next() {
        int temp = this->list.back();
        this->list.pop_back();
        return temp;
    }

    bool hasNext() {
        return this->list.size() > 0;
    }
    
    void flattenList(vector<NestedInteger> &nestedList){
        while( !nestedList.empty() ){
            NestedInteger lists = nestedList.back();
            nestedList.pop_back();
            
            if( lists.isInteger() ){
                this->list.push_back( lists.getInteger() );
            } else {
                std::vector<NestedInteger> moreLists = lists.getList();
                for(auto l : moreLists)
                    nestedList.push_back( l );
            }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
