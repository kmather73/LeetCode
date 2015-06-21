
  public ListNode deleteDuplicates(ListNode head) {
      if(head == null || head.next == null){
          return head;
      }
      
      ListNode p = head;
      ListNode q = new ListNode(0);
      head = q;
      
      while(p != null && p.next != null){
          if(p.val == p.next.val){
              int next = p.next.val;
              while(p != null && p.val == next){
                  p = p.next;
              }
              q.next = p;
          }
          else{
              q.next = p;
              q = p;
              p = p.next;
          }
      }
      return head.next;
  }
