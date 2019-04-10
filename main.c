#include <stdio.h>


int main (){
    FILE * printTest;
    FILE * encodeMeRotation;
    printTest = fopen("text.txt", "r");
    encodeMeRotation = fopen("encodeMeRotation", "r");
    int choice = 0;
    char c;
    char cha = 64;
    int a = cha;
    printf("Welcome to the Cipher Program, version: 0.2\n"); // These three lines print introductions to the programs, and its specifications
    printf("Please provide an input: \n1 for encryption, 2 for decryption.\n"); // and they provide user-friendly instructions
    printf("Currently, only rotation ciphers are implemented.\n"); // and what it is capable of.
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Please provide an input from -25 to 25\nIncluding 0 will cause no encryption.\n");
            int key;
            scanf("%d", &key);
            printf("Your key is: %d\n", key);
            if(25 < key || -25 > key){
                printf("Invalid input.");
                break;
            }
            while(1){
                int keycounter = 0;
                c = fgetc(encodeMeRotation);
                if(key == keycounter){
                    break;
                }
                if(feof(encodeMeRotation)) { 
                    break;
                }
                if(c > 90){
                    c = c-32;
                }
                while(keycounter != key && key > 0){
                    c++;
                    keycounter++;
                }
                while(keycounter != key && key < 0){
                    c--;
                    keycounter--;
                }
                if(c == 32){
                    c = 32;
                } else if(c < 65 && c != 32){
                    c = 90;
                } else if (c > 90 && c != 32){
                    c = 65;
                }
                printf("%c", c);
                
                
            }
    }
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
