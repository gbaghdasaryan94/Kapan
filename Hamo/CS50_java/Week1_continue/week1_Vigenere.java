import java.util.Scanner;


public class MyClass {
    
    
    
    static void print(Object line){
        System.out.print(line);
    }
    
    
    static void println(Object line){
        System.out.println(line);
    }
    
    
    static boolean isAlpha(String str){
        if( str == null || str.isEmpty())
        {
            return false;
        }
            for(int i=0; i<str.length(); i++){
               
                char c = str.charAt(i);
                
                if( !(c >= 'A' && c <= 'Z') && !( c >= 'a' && c <= 'z' ) ){
                    return false;
                }
            }
            
            return true;
        }
    
    
    static void encode(String key, String str){
        int num;
        int j=0;
        int k;
        String code="";
        boolean letter=true;
        
        
        for(int i = 0; i < str.length(); i++){
           
            char c = str.charAt(i);
                
            if(c >= 'A' && c <= 'Z')
            {
                char cj = key.charAt(j);
                k=(cj-65)%26;
                j++;
               
                num=(c-65 +k)%26+65;
            }
            else if (c >= 'a' && c <= 'z') 
            {
                char cj = key.charAt(j);
                k=(cj-65)%26;
                j++;
                
                num=(c-97 + k)%26+97;
            }
            else 
            {
                num = c;
            }
            
            
            char w =(char)num;
            code +=w; 
            
            if( j >= key.length() ) { j=0; }
        }
        
        println(code);
    }
    
    
    
    static int userInp(){
        
        Scanner inp = new Scanner(System.in);
        
        println("Please enter the key-word");
        
        String keyword = inp.nextLine();
        
        if ( isAlpha(keyword) ) {
            
            keyword=keyword.toUpperCase();
            
            println("Please enter the sentence you need to encode");
            
            String str = inp.nextLine();
            
            encode(keyword, str);
            
            return 0;
        }
        else
        {
            println("Sxal a eee");
            return 1;
        }
    }
    
    
    public static void main(String args[]) {
       userInp();
    }
}
