import java.util.Scanner;


public class MyClass {
    
    
    
     static void userInp(){
        long num;
        
        Scanner inp = new Scanner(System.in);
        System.out.println("Please enter card number");
        
        if( inp.hasNextLong()  ){
            num = inp.nextLong();
           if (num > 0)
           {
                totalCount(num);
           }
            else
            {
                userInp();
            }
            
        } 
            else 
        {
           
            userInp();
        }
   
    }
    
    
   
    
    
    static void totalCount(long num){
        
        
        int countNumber = 0;
        long lastNum;
        long total=0;
        long multiple; 
        long multipleNum;
        long count;
        String compName="";
       
        
        count = num;
        
        while (count != 0){
            count = count/10;
            countNumber ++;
           if ( count == 34 || count == 37){
              compName = "Amex";
              
           }
           if (count >=51 && count <= 55){

                compName = "MasterCard";
           }
           if (count == 4 ){

               compName = "Visa";
           }
        }
         
    //System.out.println(compName);
        
        for (int i= 0; i < countNumber; i++)
        {
            lastNum = num % 10;
            
            if ( i%2 != 0 )
            {
                
                multiple=lastNum*2;
                if(multiple > 9)
                {
                     for(int j=0; j<2; j++){
                        
                        multipleNum=multiple%10;
                        multiple=multiple/10;
                        total +=multipleNum;
                         
                     }
                }
                else 
                {
                    total +=multiple;
                }
            }
            else
            {
                total +=lastNum;
            }                
         
          num = num / 10;
           
        }
        
        //System.out.println("total = " + total);
        
       printInfo(total, countNumber, compName );
    
        
    }
    
    
    
   
   static void printInfo( long total, int countNumber,String compName ){
        if (total%10 == 0) {
            
            if ( (compName == "Amex" && countNumber == 16 ) || (compName == "Amex" && countNumber == 15) ){
                
                System.out.println("Your " + compName +" card Number is valid");
            }
            else if ( compName == "MasterCard" && countNumber == 16){
                
                System.out.println("Your " + compName +" card Number is valid");
            }
            else if ( (compName == "Visa" && countNumber == 13) || (compName == "Visa" && countNumber == 16) ) {
                
                System.out.println("Your " +compName +" card Number is valid");
            } 
            else 
            {
                
                System.out.println("Your credit card number is valid, but we do not know which company it belongs to.");
            }
            
            //System.out.println("Card Number is valid ...");
        }
        else 
        {
            compName = "";
            System.out.println("Card Number is not valid  !!!");
        }
    }
    
     
    
   
    
    
    public static void main(String args[]) {
        userInp();
    }
}

