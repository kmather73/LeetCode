
  public ListNode deleteDuplicates(ListNode head) {
      if(head == null || head.next == null){
          return head;
      }
      
      ListNode current = head;
      ListNode previous = new ListNode(0);
      head = previous;
      
      while(current != null && current.next != null){
          if(current.val == current.next.val){
              int next = current.next.val;
              while(current != null && current.val == next){
                  current = current.next;
              }
              previous.next = current;
          }
          else{
              previous.next = current;
              previous = current;
              current = current.next;
          }
      }
      return head.next;
  }
