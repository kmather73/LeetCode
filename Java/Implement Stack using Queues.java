class MyStack {
    Queue<Integer> q1 = new LinkedList<Integer>();
    Queue<Integer> q2 = new LinkedList<Integer>();
    int top;
    
    // Push element x onto stack.
    public void push(int x) {
        top = x;
        q1.add(x);
    }

    // Removes the element on top of the stack.
    public void pop() {
        while(q1.size() > 2)
            q2.add(q1.remove());
        
        if(q1.size() == 2){
            top = q1.peek();
            q2.add(q1.remove());
        }
        
        Queue<Integer> q = q1; 
        q1 = q2;
        q2 = q;
        q2.remove();
    }

    // Get the top element.
    public int top() {
        return top;
    }

    // Return whether the stack is empty.
    public boolean empty() {
        return q1.size() == 0;
    }
}
