public class HashTableJava {

    public static void main(String[] args) {
        stressTest();
    }
    
    public static void stressTest(){
        //this section works good
        hashTable myHash = new hashTable();
        System.out.println("Testing Insert:");
        myHash.insert("pokemon");
        myHash.insert("Hello");
        
        //This section works good
        System.out.println("Testing Iterate:");
        myHash.iterate();
        
        //
        System.out.println("Testing checking for a value that is in the hash table.");
        System.out.println(myHash.checkFor("pokemon"));
        System.out.println("Testing checking for a value that isn't in the hash table.");
        System.out.println(myHash.checkFor("False"));
        
        System.out.println("Testing deleting a value that IS in the hash table:");
        myHash.delete("Hello");
        myHash.iterate();
        
        System.out.println("Testing deleting a value that isn't in the hash table:");
        myHash.delete("False");
        myHash.iterate();
        
        System.out.println("Test is complete.");
    }
    
    
}
