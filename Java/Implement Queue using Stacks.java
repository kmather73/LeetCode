class MyQueue {
    Stack<Integer> s1 = new Stack<Integer>();
    Stack<Integer> s2 = new Stack<Integer>();
    int front;
    // Push element x to the back of queue.
    public void push(int x) {
        if(s1.size() == 0)
            front = x;
        s1.add(x);
    }

    // Removes the element from in front of queue.
    public void pop() {
        while(s1.size() > 2)
            s2.add(s1.pop());
        if(s1.size() == 2){
            front = s1.peek();
            s2.add(s1.pop());
        }
        s1.pop();
        
        while(s2.size() > 0)
                s1.add(s2.pop());
    }

    // Get the front element.
    public int peek() {
        return front;
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return s1.size() == 0;
    }
}
