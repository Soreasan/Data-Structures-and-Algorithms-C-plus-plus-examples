import java.util.Random;
public class BinarySearchTreeJava {

    public static void main(String[] args) {
        //Random r = new Random();
        //binarySearchTree tree = new binarySearchTree();
        //for(int i = 0; i < 10; i++){
        //    tree.add(r.nextInt(100));
        //}
        //tree.preOrderTraversal();
        //tree.inOrderTraversal();
        //tree.postOrderTraversal();
        //tree.add(10);
        //System.out.println(tree.checkFor(10));
        testDelete();
    }
    
    public static void testDelete(){
        binarySearchTree test = new binarySearchTree();
        test.add(4);
        test.add(2);
        test.add(6);
        test.add(1);
        test.add(3);
        test.add(5);
        test.add(7);
        System.out.println("Should be 1-7");
        test.inOrderTraversal();
        System.out.println("Next 1 should be missing");
        System.out.println("This tests removing a node with no children.");
        test.delete(1);
        test.inOrderTraversal();
        System.out.println("Next 2 should be missing.");
        System.out.println("This tests removing a node with one child[3]");
        test.delete(3);
        test.inOrderTraversal();
        System.out.println("Next 6 should be missing.");
        System.out.println("This tests removing a node with two children[5, 7]");
        test.delete(6);
        test.inOrderTraversal();
    }
    
}
