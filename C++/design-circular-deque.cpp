class MyCircularDeque {
vector<int> m_q;
int m_start;
int m_end;    
int m_k;
    
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) : m_start(0), m_end(0), m_k(k) {
        m_q = vector<int>(k+1);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        auto success = false;
        if(!isFull())   
        {
            m_start = (m_k + m_start) % (m_k + 1);
            m_q[m_start] = value;
            success = true;
        }
        
        return success;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        auto success = false;
        if(!isFull())   
        {
            m_q[m_end] = value;
            m_end = (m_end + 1) % (m_k + 1);
            success = true;
        }
        
        return success;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        auto success = false;
        if (!isEmpty())
        {
           m_start = (m_start + 1) % (m_k + 1);
           success = true;
        }
        
        return success;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        auto success = false;
        if (!isEmpty())
        {
           m_end = (m_k + m_end) % (m_k + 1);
           success = true;
        }
        
        return success;
    }
    
    /** Get the front item from the deque. */
    inline int getFront() {
        return isEmpty() ? -1 : m_q[m_start];
    }
    
    /** Get the last item from the deque. */
    inline int getRear() {
        return isEmpty() ? -1 : m_q[(m_k + m_end) % (m_k + 1)]; 
    }
    
    /** Checks whether the circular deque is empty or not. */
    inline bool isEmpty() {
        return m_start == m_end;
    }
    
    /** Checks whether the circular deque is full or not. */
    inline bool isFull() {
        return m_start == (m_end + 1) % (m_k + 1);
    }
};
