//Recursive Code
    public int countNodes(TreeNode root) {
        if(root == null){
            return 0;
        }
        
        int leftHeight = leftHeight(root);
        int rightsLeftHeight = leftHeight(root.right);
        
        if(leftHeight == rightsLeftHeight + 1){
            return (1 << rightsLeftHeight ) + countNodes(root.right);
        }
        else{
            return (1 << rightsLeftHeight )  + countNodes(root.left);
        }
    }
    
    public int leftHeight(TreeNode root){
        int height = 0;
        
        while(root != null){
            ++height;
            root = root.left;
        }
        return height;
    }
    
    
    //Iterative code    
        public int countNodes(TreeNode root) {
        if(root == null){
            return 0;
        }
        int total = 0;
        while(root != null){
            int leftHeight = leftHeight(root.left);
            int rightsLeftHeight = leftHeight(root.right);
        
            if(leftHeight == rightsLeftHeight){
                total += 1 << rightsLeftHeight;
                root = root.right;
            }
            else{
                total += 1 << rightsLeftHeight;
                root = root.left;
            }
        }
        return total;
    }
    
    public int leftHeight(TreeNode root){
        int height = 0;
        
        while(root != null){
            ++height;
            root = root.left;
        }
        return height;
    }
