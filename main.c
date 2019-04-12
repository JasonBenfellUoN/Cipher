#include <stdio.h>
char rotation(char c, int key);

int main (){
    FILE * printTest;
    FILE * encodeMeRotation; //Points to a file under the name "encodeMeRotation"
    printTest = fopen("text.txt", "r"); 
    encodeMeRotation = fopen("encodeMeRotation", "r"); //Opens the file "encodeMeRotation" for "reading" (r)
    int choice = 0; //Initialises variables, an integer for user choice.
    int n;
    char c;
    char cha = 64;
    int a = cha;
    printf("Welcome to the Cipher Program, version: 1.2\n"); // These three lines print introductions to the programs, and its specifications
    printf("Please provide an input: \n1 for encryption, 2 for decryption.\n"); // and they provide user-friendly instructions
    printf("Currently, only rotation ciphers are implemented.\n"); // and what it is capable of.
    scanf("%d", &choice);
    int i = 0;
    if(choice == 1){
            printf("Please provide an input from -25 to 25\nIncluding 0 will cause no encryption.\n");
            int key;
            scanf("%d", &key);
            printf("Your key is: %d\n", key);
            if(25 < key || -25 > key){
                printf("Invalid input.\n");
            }
            
            while(!feof(encodeMeRotation)){
                c = fgetc(encodeMeRotation);
                
                if(c > 90){ //Detects lowercase letters (all ASCII lowercase letters are greater than 90)
                    c = c-32; //Takes any character that is a lowercase letter and changes it into a capital letter (the difference between an ASCII lower and upper case is exactly 32)
                }
                if ((c < 65) || (c> 90)) {
                    printf("%d %c %c\n", i, c, c);
                } else {
                
                i++;
                printf("%d %c", i, c);
                c += key;
                if(c < 65){
                    c = 155 - c;
                } else if(c > 90){
                    c = c - 26;
                }
                printf(" %c\n", c);     
            }
            }
        } else if(choice == 2){

            printf("Please provide a key as a number\nIncluding 0 will cause no encryption.\n");
            int key;
            scanf("%d", &key);
            printf("Your key is: %d\n", key);
            if(25 < key || -25 > key){
                printf("Invalid input.\n");
            }
            
            while(!feof(encodeMeRotation)){
                c = fgetc(encodeMeRotation);
                
                if(c > 90){ //Detects lowercase letters (all ASCII lowercase letters are greater than 90)
                    c = c-32; //Takes any character that is a lowercase letter and changes it into a capital letter (the difference between an ASCII lower and upper case is exactly 32)
                }
                if ((c < 65) || (c> 90)) {
                    printf("%d %c %c\n", i, c, c);
                } else {
                
                i++;
                printf("%d %c", i, c);
                c += key;
                if(c < 65){
                    c = 155 - c;
                } else if(c > 90){
                    c = c - 26;
                }
                printf(" %c\n", c);     
            }
        }
    } else{
            printf("I hate my life.");
        }

        

     /*           while(keycounter != key && key < 0){
                    if(c == 32){
                        c = 32;
                    } else if(c > 65 && c < 91 && c != 32){
                        c--;
                        keycounter--;
                    } else if(c < 65 && c != 32){
                        c = 90;
                    } else if (c > 90 && c != 32){
                        c = 65;
                    }
                } */
                
    
    while(1) {
        c = fgetc(printTest);
        if(feof(printTest)) { 
            break;
        }
        if(c > 90){ //Detects lowercase letters (all ASCII lowercase letters are greater than 90)
            c = c-32; //Takes any character that is a lowercase letter and changes it into a capital letter (the difference between an ASCII lower and upper case is exactly 32)
        }
        printf("%c", c);
    }

    fclose(printTest);
    printf("\n%d \n", a);
    printf("%c", cha);

    printf("\nProgram terminated.\n");
    return 0;
}

char rotation(char c, int key){ //function that operates the 
    
}
