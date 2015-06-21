//Works only if the list is sorted, check below for the version that works if the list is unsorted.
  public ListNode deleteDuplicates(ListNode head) {
      ListNode p = head;
      
      while(p != null && p.next != null){
          if(p.val != p.next.val){
              p = p.next;
          }
          else{
              p.next = p.next.next;
          }
      }
      return head;
  }

//Works even if the list is not sorted.
  public ListNode deleteDuplicates(ListNode head) {
      if(head == null){
          return head;
      }
      HashSet<Integer>  numbersSeen = new HashSet<Integer>();
      ListNode q = head;
      ListNode p = q.next;
      
      numbersSeen.add(head.val);
      
      while(p != null){
          while(p != null && numbersSeen.contains(p.val))
            p = p.next;

          q.next = p;
          q = p;
         if(p != null){
              numbersSeen.add(p.val);
              p = p.next;
          }
      }
      return head;
  }
