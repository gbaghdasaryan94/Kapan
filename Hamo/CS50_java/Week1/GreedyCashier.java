<<<<<<< HEAD
﻿import java.util.Scanner;
=======
import java.util.Scanner;
>>>>>>> 18537d8cfa3a04b59b76d2403e1c6704c3581f0a

public class GreedyCashier{
    
    static void userInp(){
        
        
       Scanner inp= new Scanner(System.in);
        System.out.println("Hai! How much change is owed?");
        
       
            
            if( inp.hasNextFloat() )
            {
               Float cent = inp.nextFloat();
               
               if (cent > 0) {
              
                    //convert float to integer 
                
                    int num = Math.round(cent*100);
                    
                    
                    totalCoins(num);
                } 
                else 
                {
                    System.out.println("Please enter the valid number");
                    userInp();
                }
            } 
            else 
            {
                System.out.println("Please enter the number");
                 userInp();
            }
            
         
    }
    
     static void totalCoins(int total){
         int[] coins = {50, 25, 10, 5, 1};
         
         int[] quantity={0, 0, 0, 0, 0};
         
         int quan=0;
         
        
         System.out.println("amboxjy esa _____ " + total);
        
             for(int i=0; i<coins.length; i++){
<<<<<<< HEAD
                
                while(total>=coins[i]){
                    total = total - coins[i];
                    quantity[i]++;
                   
                }
=======
              
                if( total>=coins[i] ){            
            	    quantity[i]=quantity[i]+total/coins[i];
            	    total=total%coins[i];
        	}
                   
                
>>>>>>> 18537d8cfa3a04b59b76d2403e1c6704c3581f0a
                
             }
             
            
             for (int i =0 ; i < quantity.length; i++) {
<<<<<<< HEAD
=======
                 
                 if(quantity[i] !=0){
>>>>>>> 18537d8cfa3a04b59b76d2403e1c6704c3581f0a
                  
                  System.out.println(coins[i]+" cent pieces given = " + quantity[i]);
                  
                  quan = quan+quantity[i];
<<<<<<< HEAD
=======
                 }
>>>>>>> 18537d8cfa3a04b59b76d2403e1c6704c3581f0a
                }
            System.out.println("totaly given = " + quan);
          
     }
    
    
    public static void main(String args[]) {
         
        
        userInp();
    }
<<<<<<< HEAD
}
=======
}
>>>>>>> 18537d8cfa3a04b59b76d2403e1c6704c3581f0a
