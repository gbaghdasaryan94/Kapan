import java.util.Scanner;



public class MyClass {
    
    static void println(Object line)
        {
            System.out.println(line);
        }
        
    static void print(Object line)
        {
            System.out.print(line);
        }
    
    
    
    

    
    
    static  int userInput(){
        
        int num;
        String cod=""; 
        
        
        Scanner sent = new Scanner(System.in);

        println("Please enter the key and the sentence you need to encode");
        
        
        if (sent.hasNextInt() ){

            int key= sent.nextInt();
            String str= sent.nextLine();
            
            if (key > 0 )
            {
                
                if( str != null && !str.isEmpty() && !str.trim().isEmpty() )
                {
                
                    
                    str = str.trim();
                    

                    
                    for ( int i=0; i<str.length(); i++ ){
                      
                        int index = str.charAt(i);
                       
                        if ( index>=65 && index<=90 )
                        {
                            num = ((index-65+key)%26)+65;
                        } 
                        else if ( index>=97 && index<=122 )
                        {
                            num = ((index-97+key)%26)+97;
                        }  
                        else 
                        {
                            num = index;
                        }  
                        
                        char c=(char)num;
                       
                        cod +=c;
                    }
                    
                    
                       
                    
                    println(cod);
                    return 0;
                }
                else
                {
                  println("You did not write a sentence that you need to encode"); 
                  return 1;
                }
                
            }
            else
            {
                println("Тhe key must be a positive number");
                return 1;
            }
        
        }
        else 
        {
            println("The key must be a number");
            return 1;
        }
        
        
        
    }
    
    
    public static void main(String args[]) {
       userInput();
    }
}
