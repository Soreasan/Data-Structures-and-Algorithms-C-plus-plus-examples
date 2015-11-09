public class linkedList {
    private node head;
    private node tail;
    private int count;
    
    public linkedList(){
        head = null;
        tail = null;
        count = 0;
    }
    
    //Since we're only using this linked list for chaining it will add to the end
    public void add(String data){
        node newNode = new node(data);
        count++;
        if(count == 1){
            head = newNode;
            tail = newNode;
        }else{
            tail.next = newNode;
            tail = newNode;
        }
    }
    
    public boolean checkFor(String data){
        node pointer = head;
        for(int i = 0; i < count; i++){
            if(pointer.data == data){
                return true;
            }else{
                pointer = pointer.next;
            }
        }
        return false;
    }
    
    public void delete(String data){
        node pointer = head;
        //runner will trail one node behind pointer
        node runner = head;
        for(int i = 0; i < count; i++){
            if(pointer.data == data){
                runner.next = pointer.next;
            }else{
                runner = pointer;
                pointer = pointer.next;
            }
        }
    }
    
    public void iterate(){
        node pointer = head;
        for(int i = 0; i < count; i++){
            System.out.println(pointer.data);
            pointer = pointer.next;
        }
    }
}
