import java.util.Scanner;

public class MarioFullPyramid {
    
    static void usrInp(){
        Scanner inp = new Scanner(System.in);
        
        if (inp.hasNextInt()){
             int height = inp.nextInt();
            
        
            if (height < 1 || height > 23 ){
                 System.out.println("Pyramid height must be more thane 0, less than 23");
                 System.out.println("Please enter valid pyramid height");
                 usrInp();
            } else {
                makePyramid(height);
            }
        }
        else {
            System.out.println("Please input number");
            usrInp();
        }
    }
    
    static void makePyramid(int n){
       
       for(int i=0; i<n; i++){
           for(int j=n-1; j>=0; j--){
               if( j > i ){
                   System.out.print(".");
               } else {
                  System.out.print("#"); 
               }
           }
           
          System.out.print(" ");
           
          for(int j=0; j<n; j++){
              if( j > i ){
                  System.out.print(".");
              } else {
                  System.out.print("#"); 
              }
          }
           
           System.out.println(" ");
       }
    }
    
    public static void main(String args[]) {
        System.out.println("Enter pyramid height");
        usrInp();
        
    }
}
