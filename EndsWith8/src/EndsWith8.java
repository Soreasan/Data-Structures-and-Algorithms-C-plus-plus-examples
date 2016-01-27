public class EndsWith8 {

    public static void main(String[] args) {
        int X;
        boolean Y;
        if(args.length >= 1){
            X = Integer.parseInt(args[0]);
            Y = EndsWith8(X);
            System.out.println("X = " + X + " Member?   " + Y);
        }
    }
    
    public static boolean EndsWith8(int x){
        if(x == 8) return true;
        if(x < 8) return false;
        
        return EndsWith8(x - 10);
    }
    
}
