class MinStack {
    private LinkNode head;
    
    class LinkNode{
        public int val;
        public int min;
        public LinkNode next;
        
        public LinkNode(int val, int min){
            this.val = val;
            this.min = min;
        }
    }
    
    public void push(int x) {
        if(head == null){
            head = new LinkNode(x,x);
        }
        else{
            LinkNode newhead = new LinkNode(x, Math.min(getMin(),x));
            newhead.next = head;
            head = newhead;
        }
    }

    public void pop() {
        head = head.next;
    }

    public int top() {
        return head.val;
    }

    public int getMin() {
        return head.min;
    }
}
