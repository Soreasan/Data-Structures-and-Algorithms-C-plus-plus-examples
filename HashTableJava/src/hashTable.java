public class hashTable {
    private linkedList[] arr;
    private int size;
    
    public hashTable(){
        size = 128;
        arr = new linkedList[size];
        for(int i = 0; i < size; i++){
            arr[i] = new linkedList();
        }
    }
    /*A Hash function takes some input and generates an INDEX NUMBER/KEY that is
    somehow based off that key.  The same input must always product the same output.  
    However the Hash function has to return essentially random numbers or else you won't 
    get a good distribution. Once you generate a random number you use a MODULUS to
    get the remainder of your number divided by the total number of slots available
    in an array and then use that number as the index you use in the array.  
    To manage collisions you make each slot in the array a linked list rather than
    just a node.  Then you can have collisions without erasing data.*/
    public int hashFunction(String data){
        //Converts a string to an array of characters so we can extract the ASCII code
        char[] arr = data.toCharArray();
        //This HASH code will get really really big from our equation.  
        int hashCode = 0;
        //This FOR loop goes through every character in the character array
        for(int i = 0; i < arr.length; i++){
            //You could use a lot of different equations.  I just picked this one.  
            //My equation takes the current hash code, multiplies it by itself, then
            //takes the ascii value of each letter and adds that to the hash code.  
            //Each letter has an ASCII or UNICODE value that is a number.  
            //For example an "A" might have a value of 111 or something like that.  
            //This means we can do math with the letters in the words.  
            hashCode = hashCode * 31 + (int) arr[i];
        }
        //Once we have an enormous number we use the absolute value of the number 
        //since if a number gets too big for the integer data type it will roll over
        //and become negative.  After that we take the MODULUS or REMAINDER of the
        //division and return that number as the INDEX slot for INSERTS/DELETES/RETRIEVES
        return Math.abs(hashCode) % size;
    }
    
    /*
    Once we have the HASH function setup everything else is easy.  Basically we
    put the String into the hash function to get the index we need to use, then
    simply use the methods of the linked lists at that specific linked list at that
    specific index in the array of linked lists.  
    */
    
    public void insert(String data){
        int key = hashFunction(data);
        arr[key].add(data);
    }
    
    public boolean checkFor(String data){
        int key = hashFunction(data);
        return arr[key].checkFor(data);
    }
    
    public void delete(String data){
        int key = hashFunction(data);
        arr[key].delete(data);
    }
    
    public void iterate(){
        for(int i = 0; i < size; i++){
            arr[i].iterate();
        }
    }
}
