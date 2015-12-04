public class linkedList {
    //Stores the location of the front node
    private node head;
    //Stores the location of the rear node
    private node tail;
    //Stores how many nodes are in the linked list
    private int count;
    
    //constructor
    public linkedList(){
        head = null;
        tail = null;
        count = 0;
    }
    
    //Since we're only using this linked list for chaining it will add to the end
    public void add(String data){
        //Creates the new node with the data
        node newNode = new node(data);
        //Updates the count since we have a new node
        count++;
        //If this is the only node in the linked list make the head and tail point to it
        if(count == 1){
            head = newNode;
            tail = newNode;
            //If this isn't the first node update the tail to point to the new node and
            //update the previous tail's pointer to point to the new node
        }else{
            tail.next = newNode;
            tail = newNode;
        }
    }
    
    //Just checks to see if the linked list has a node with a specific string in it
    public boolean checkFor(String data){
        //pointer is a temporary node that is used to iterate through the list
        node pointer = head;
        //This FOR loop goes through the entire linked list
        for(int i = 0; i < count; i++){
            //If we find the data return true
            if(pointer.data == data){
                return true;
                //If we don't find the data in this specific node move to the next one
            }else{
                pointer = pointer.next;
            }
        }
        //Once we've gone through the whole linked list and found nothing we return false
        return false;
    }
    
    //removes a node from the linked list
    public void delete(String data){
        //pointer is a temporary node that is used to iterate through the list
        node pointer = head;
        //runner will trail one node behind pointer
        node runner = null;
        //This FOR loop goes through the entire linked list
        for(int i = 0; i < count; i++){
            //If we find the node we update the pointers so that the linked list "skips" the node we're deleting.
            if(pointer.data == data){
                //Since we're removing a node decrement the count or we get null pointer exceptions
                count--;
                //If the node we're deleting is the first one, just update the head to the second node
                if(i == 0){
                    head = pointer.next;
                }
                //This is actually the default scenario.  
                //update the pointers to skip over the deleted node.
                else if(pointer.next != null){
                    runner.next = pointer.next;
                //If this is the last node, just set it to null
                }else{
                    runner.next = null;
                }
                return;
                //If this node isn't the one we're looking for go to the next node
            }else{
                runner = pointer;
                pointer = pointer.next;
            }
        }
    }
    
    //Iterate just prints all the contents of the node.  
    public void iterate(){
        //pointer is a temporary node that is used to iterate through the list
        node pointer = head;
        //This FOR loop goes through the entire linked list
        for(int i = 0; i < count; i++){
            //Print the data and then move to the next node
            System.out.println(pointer.data);
            pointer = pointer.next;
        }
    }
}
