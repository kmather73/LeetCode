class MedianFinder {
    int i = 0;
    Queue[] q = {new PriorityQueue<Integer>(Collections.reverseOrder()), new PriorityQueue<Integer>()};
    
    
    // Adds a number into the data structure.
    public void addNum(int num) {
        q[i].add(num);
        q[i ^= 1].add(q[i^1].poll());
    }

    // Returns the median of current data stream
    public double findMedian() {
        return ((int)q[1].peek() + (int)q[i].peek() ) / 2.0;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf = new MedianFinder();
// mf.addNum(1);
// mf.findMedian();
