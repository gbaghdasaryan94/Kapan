#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>

int main(int argc, string argv[])
{

    if(argc != 2){  
        printf("Usage: ./crack hash\n");
        return 1;
    }
    
    const int letter_count = 53;
    string letter = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    string hash = argv[1];
    char a[3] = {hash[0], hash[1],'\0'};
    // char key[6] = "\0\0\0\0\0\0";

    // one two three four five
    for (int five = 0; five < letter_count; five++)
    {
        for (int four = 0; four < letter_count; four++)
        {
            for (int three = 0; three < letter_count; three++)
            {
                for (int two = 0; two < letter_count; two++)
                {
                    for (int one = 0; one < letter_count; one++)
                    {
                        char key[6] = {
                            letter[one],
                            letter[two],
                            letter[three],
                            letter[four],
                            letter[five],
                            '\0'
                        };
                        printf("%s \n", key);

                        if (!strcmp(crypt(key,a),hash))
                        {
                            printf("Success / %s / crypt = %s <=> hash = %s\n", key,crypt(key,a),hash);
                            return 0;
                        }
                    }
                }
            }
        }
    }
                    
    return 2; 

}