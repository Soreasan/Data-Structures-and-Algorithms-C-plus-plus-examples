/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Kenneth
 */
public class binarySearchTree {
    //This is the start of our tree
    private node root;
    
    public binarySearchTree(){
        root = null;
    }
    
    public void add(int data){
        node myNode = new node(data);
        //If the tree is empty, make the node the root and then exit
        if(root == null){
            root = myNode;
            return;
        }
        //traverse to the correct spot
        node pointer = root;
        while(pointer != null){
            //If the data is bigger than the node we're on and the right pointer
            //is null, insert it and make the pointer null
            if(myNode.data > pointer.data && pointer.right == null){
                pointer.right = myNode;
                pointer = null;
            //If the data is smaller than the node we're on and the left pointer
            //is null, insert it and make the pointer null
            }else if(myNode.data <= pointer.data && pointer.left == null){
                pointer.left = myNode;
                pointer = null;
            //If the data is larger than the node we're on but the right pointer
            //isn't null just move to the next node
            }else if(myNode.data > pointer.data){
                pointer = pointer.right;
            //If the data is smaller than the node we're on but the left pointer
            //isn't null just move to the next node
            }else{
                pointer = pointer.left;
            }
        }
    }
    
    public boolean checkFor(int data){
        if(root == null){
            return false;
        }
        node pointer = root;
        while(true){
            if(data == pointer.data){
                return true;
            }
            else if(data > pointer.data && pointer.right == null){
                return false;
            }else if(data <= pointer.data && pointer.left == null){
                return false;
            }else if(data > pointer.data){
                pointer = pointer.right;
            }else{
                pointer = pointer.left;
            }
        }
    }
    
    public void delete(int data){
        if(root == null){
            return;
        }
        node pointer = root;
        node runner = null;
        //First navigate to the correct node
        while(true){
            //When we find the right node...
            if(data == pointer.data){
                break;
            }
            //These two IF statements mean there's nothing to delete
            else if(data > pointer.data && pointer.right == null){
                return;
            }else if(data <= pointer.data && pointer.left == null){
                return;
            }else if(data > pointer.data){
                runner = pointer;
                pointer = pointer.right;
            }else{
                runner = pointer;
                pointer = pointer.left;
            }
        }
        //At this point we should be at the correct node with the runner node being one node behind us
        
        //First case is that the node to be deleted has no children.  This is the easiest.  
        if(pointer.left == null && pointer.right == null){
            if(pointer.data > runner.data){
                runner.right = null;
            }else{
                runner.left = null;
            }
            return;
        }
        
        //Second case is that node has one child.  This one is also easy. This one is left node is being deleted 
        if(pointer.left != null && pointer.right == null){
            runner.left = pointer.left;
            return;
        }
        //Second case is that node has one child.  This one is also easy. This one is right node is being deleted 
        if(pointer.right != null && pointer.left == null){
            runner.right = runner.right;
            return;
        }
        
        //Third and most difficult case is that the node has two children.  
        //In this case go right one node.  Then go left as far as possible.  
        //Make the value of the node to be deleted equal to this node we just found
        //Then delete the node we just retrieved the value of.  
        //This website is amazing: http://www.algolist.net/Data_structures/Binary_search_tree/Removal
        if(pointer.right != null && pointer.left != null){
            node temp = pointer;
            node tempRunner = pointer;
            temp = temp.right;
            while(temp.left != null){
                tempRunner = pointer;
                temp = temp.left;
            }
            pointer.data = temp.data;
            //On the rare occassion that the node to be deleted only has one node to the right with no children
            if(pointer.right == temp){
                tempRunner.right = null;
            }else{
                tempRunner.left = null;
            }
            return;
        }
        
        //If it gets this far there is an unknown bug but I think I covered all scenarios
        return;
    }
    
    private void inOrderTraversal(node thisNode){
        if(thisNode != null){
            inOrderTraversal(thisNode.left);
            System.out.println(thisNode.data);
            inOrderTraversal(thisNode.right);
        }
    }
    
    public void inOrderTraversal(){
        inOrderTraversal(root);
    }
    
    private void preOrderTraversal(node thisNode){
        if(thisNode != null){
            System.out.println(thisNode.data);
            preOrderTraversal(thisNode.left);
            preOrderTraversal(thisNode.right);
        }
    }
    
    public void preOrderTraversal(){
        preOrderTraversal(root);
    }
    
    private void postOrderTraversal(node thisNode){
        if(thisNode != null){
            preOrderTraversal(thisNode.left);
            preOrderTraversal(thisNode.right);
            System.out.println(thisNode.data);
        }
    }
    
    public void postOrderTraversal(){
        postOrderTraversal(root);
    }
    
    public void iterate(){
        inOrderTraversal(root);
    }
}
