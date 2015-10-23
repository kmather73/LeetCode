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
            TreeLinkNode bottom;
            TreeLinkNode nextRow = top;
            
            while(nextRow != null)
            {
                do{
                    if(nextRow.left != null){    
                        nextRow = nextRow.left;
                        break;   
                    }
                    else if(nextRow.right != null){
                        nextRow = nextRow.right;
                        break;   
                    }
                    else
                        nextRow = nextRow.next;
                        
                }while(nextRow != null);
                bottom = nextRow;
                
                while(top != null && bottom != null ){
                    if( top.left != nextRow && top.left != null){
                            bottom.next = top.left;
                            bottom = bottom.next;
                    }
                    
                    if(top.right != nextRow && top.right != null){
                        bottom.next = top.right;
                        bottom = bottom.next;
                    }
                    
                    top = top.next;
                }
                
                top = nextRow;
            }
        }
    }
}
