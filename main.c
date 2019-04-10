#include <stdio.h>


int main (){
    FILE * printTest;
    printTest = fopen("text.txt", "r");
    textToEncode = fopen("encodeMeRotation", r);
    int choice = 0;
    char c;
    char cha = 64;
    int a = cha;
    printf("Welcome to the Cipher Program, version: 0.2\n"); // These three lines print introductions to the programs, and its specifications
    printf("Please provide an input: \n1 for encryption, 2 for decryption.\n"); // and they provide user-friendly instructions
    printf("Currently, only rotation ciphers are implemented.\n"); // and what it is capable of.
    scanf("%d", &choice);
    switch(choice){
        case: '1':
            int key;
            printf("Please provide an input from -25 to 25\nIncluding 0 will cause no encryption.");
            scanf("%d", &key);
            if(25 < key || -25 > key){
                printf("Invalid input.");
                break;
            }
            int keycounter = key;
            while(1){
                c = fgetc(printTest);
                if(c > 90){
                    c = c-32;
                }
                c = c+key;
                if(c < 65)
                
                
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

    printf("\nProgram terminated.");
    return 0;
}
