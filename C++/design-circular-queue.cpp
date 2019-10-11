class MyCircularQueue {
vector<int> m_q;
int m_start;
int m_end;
int m_k;    
    
    public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : m_start(0), m_end(0), m_k(k) {
        m_q = vector<int>(k+1);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        auto success = false;
        if(!isFull())
        {
            m_q[m_end] = value;
            m_end = (m_end + 1) % (m_k + 1);
            success = true;
        }
        
        return success;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        auto success = false;
        if(!isEmpty())
        {
            success = true;
            m_start = (m_start + 1) % (m_k + 1);
        }
        
        return success;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return isEmpty() ? -1 : m_q[m_start];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty() ? -1 : m_q[(m_k + m_end) % (m_k + 1)];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return m_start == m_end;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (m_end + 1) % (m_k + 1) == m_start;
    }
};
