public class node {
    //The actual data/information stored in the node.  Everything else is overhead.
    public String data;
    //I treat next as a pointer that gives directions to the next node
    public node next;
    
    //Constructor
    node(String data){
        this.data = data;
        this.next = null;
    }
}
