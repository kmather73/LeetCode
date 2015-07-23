// Takes O(nlg(k)) time and O(k) memory.
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int k = lists.length;
        if(k == 0 )
            return null;
        Comparator<ListNode> myComparator = new Comparator<ListNode>(){
            public int compare(ListNode l1,ListNode l2){
                if (l1.val < l2.val)
                    return -1;
                else if (l1.val == l2.val)
                    return 0;
                else 
                    return 1;
            }
        };
            
        PriorityQueue<ListNode> minHeap = new PriorityQueue<ListNode>(k,myComparator); 
        for(int i = 0; i < k; ++i)
            if(lists[i] != null)
                minHeap.add(lists[i]);
        
        ListNode fakeHead = new ListNode(0);
        ListNode p = fakeHead;
        
        while(minHeap.size() != 0){
            ListNode head = minHeap.poll();
            p.next = head;
            p = p.next;
            head = head.next;
            if(head != null)
                minHeap.add(head);
        }
        return fakeHead.next;
    }
}

//Time limit exceeded for the last test case.
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int k = lists.length;
        if(k == 0 )
            return null;
            
        PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>(k);
        
        
        for(int i = 0; i < k; ++i)
            if(lists[i] != null)
                minHeap.add(lists[i].val);
        
        ListNode fakeHead = new ListNode(0);
        ListNode p = fakeHead;
        
        while(minHeap.size() != 0){
            int minVal = minHeap.poll();
            for(int i = 0; i < k; ++i){
                ListNode currentList = lists[i];
                if( currentList != null && currentList.val == minVal){
                    p.next = currentList;
                    p = p.next;
                    lists[i] = currentList.next;
                    
                    if(currentList.next != null)
                        minHeap.add(currentList.next.val);
                    break;
                }
            }
        }
        return fakeHead.next;
    }
}


//Updated to the new method signature. Had TLE error.
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int k = lists.length;
        if(k == 0)
            return null;
        if(k == 1)
            return lists[0];
            
            
        ListNode fakeHead = new ListNode(0); // the fakehead of the sorted list.
        ListNode p1 = fakeHead;
        
        int count = 0;// counts how many of given lists are empty at a give time.
        
        while(true){
            int index = minOfK(lists);
            if(index == -1)
                break;
            p1.next = lists[index];
            p1 = p1.next;
            lists[index] = lists[index].next;
        }
        return fakeHead.next;
    }
    
    public int minOfK(ListNode[] pointers){//return the index of the smallest of the k elements in the array.
        int k = pointers.length;
        int index = -1;
        int min = Integer.MAX_VALUE;
        
        for(int i = 0; i<k; i++){
            if(pointers[i] != null){
                if(pointers[i].val <= min){
                    index = i;
                    min = pointers[i].val;
                }
            }
        }
        return index;
    }
}


//Old meathod signature.
public class Solution {
    public ListNode mergeKLists(List<ListNode> lists) {
        int k = lists.size();
        if(k == 0){
            return null;
        }
        if(k == 1){
            return lists.get(0);
        }
        ListNode[] pointers = new ListNode[k];
        
        for(int i = 0; i<k; i++){//set points to the head of each list
            ListNode p = new ListNode(0);
            p = lists.get(i);
            pointers[i] = p;
        }
        
        ListNode fakeHead = new ListNode(0); // the fakehead of the sorted list.
        ListNode p1 = fakeHead;
        
        int count = 0;// counts how many of given lists are empty at a give time.
        
        while(true){
            int index = minOfK(pointers);
            if(index == -1){
                break;
            }
            p1.next = pointers[index];
            p1 = p1.next;
            pointers[index] = pointers[index].next;
         
        }
        return fakeHead.next;
    }
    
    public int minOfK(ListNode[] pointers){//return the index of the smallest of the k elements in the array.
        int k = pointers.length;
        int index = -1;
        int min = Integer.MAX_VALUE;
        
        for(int i = 0; i<k; i++){
            if(pointers[i] != null){
                if(pointers[i].val <= min){
                    index = i;
                    min = pointers[i].val;
                }
            }
        }
        return index;
    }
}
