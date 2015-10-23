/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        if(root != null)
        {
            TreeLinkNode top = root;
            TreeLinkNode nextRow = root.left;
        
            while(nextRow != null)
            {
                while(top != null)
                {
                    top.left.next = top.right;
                    if(top.next != null)
                        top.right.next = top.next.left;
                    
                    top = top.next;
                }
                
                top = nextRow;
                nextRow = nextRow.left;
            }
        }
    }
}
