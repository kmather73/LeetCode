
//This updated version uses a arrayList to make use of random access to speed things up by about a factor of 1.7 
public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        ArrayList<TreeNode> pathToP = findPathToNode(root, p);
        ArrayList<TreeNode> pathToQ = findPathToNode(root, q);
        
        int size = Math.min(pathToP.size(), pathToQ.size() );
        for(int i = 0; i < size; ++i){
            if(pathToP.get(i) != pathToQ.get(i))
                return pathToP.get(i-1);
        }
        return pathToP.get(size - 1);
    }
    
    public ArrayList<TreeNode> findPathToNode(TreeNode root, TreeNode p){
        ArrayList<TreeNode> path = new ArrayList<TreeNode>();
        Stack<TreeNode> myStack = new Stack<TreeNode>();
        myStack.push(root);
        
        TreeNode current = null;
        
        while(current != p){
            current = myStack.pop();
            
            if(current != null){
                path.add(current);
                myStack.push(current.right);
                myStack.push(current.left);
            }
            else{
                while(myStack.peek() == null)
                    myStack.pop();
                
                current = myStack.peek();
                while(path.get(path.size()-1).right != current)
                    path.remove(path.size()-1);
                current = null;
            }
        }
        return path;
    }
}

//This is the original version that ues a linked list; which makes it kinda slow.
public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        LinkedList<TreeNode> pathToP = findPathToNode(root, p);
        LinkedList<TreeNode> pathToQ = findPathToNode(root, q);
        
        int size = Math.min(pathToP.size(), pathToQ.size() );
        for(int i = 0; i < size; ++i){
            if(pathToP.get(i) != pathToQ.get(i))
                return pathToP.get(i-1);
        }
        return pathToP.get(size - 1);
    }
    
    public LinkedList<TreeNode> findPathToNode(TreeNode root, TreeNode p){
        LinkedList<TreeNode> path = new LinkedList<TreeNode>();
        Stack<TreeNode> myStack = new Stack<TreeNode>();
        myStack.push(root);
        
        TreeNode current = null;
        
        while(current != p){
            current = myStack.pop();
            
            if(current != null){
                path.add(current);
                myStack.push(current.right);
                myStack.push(current.left);
            }
            else{
                while(myStack.peek() == null)
                    myStack.pop();
                
                current = myStack.peek();
                while(path.getLast().right != current)
                    path.removeLast();
                current = null;
            }
        }
        return path;
    }
}
