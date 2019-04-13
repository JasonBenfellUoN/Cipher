#include <stdio.h>
char rotation(char c, int key); 

int main (){
    FILE * printTest;
    FILE * encodeMeRotation; //Points to a file under the name "encodeMeRotation"
    FILE * decodeMeRotation;
    printTest = fopen("text.txt", "r"); 
    encodeMeRotation = fopen("encodeMeRotation", "r"); //Opens the file "encodeMeRotation" for "reading" (r)
    decodeMeRotation = fopen("decodeMeRotation", "r");
    int choice = 0; //Initialises variables, an integer for user choice.
    int n;
    char c;
    char cha = 64;
    int a = cha;
    int lettNum[26];
    int counter = 0;
    printf("Welcome to the Cipher Program, version: 1.3\n"); // These three lines print introductions to the programs, and its specifications
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
    }else if(choice == 2){

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
    }else if(choice == 3){
            while(!feof(decodeMeRotation)){
                c = fgetc(decodeMeRotation);
                switch(c){
                    case 65: 
                        lettNum[0] += 1;
                        break;
                    case 66:
                        lettNum[1] += 1;
                        break;
                    case 67:
                        lettNum[2] += 1;
                        break;
                    case 68:
                        lettNum[3] += 1;
                        break;
                    case 69:
                        lettNum[4] += 1;
                        break;
                    case 70:
                        lettNum[5] += 1;
                        break;
                    case 71:
                        lettNum[6] += 1;
                        break;
                    case 72:
                        lettNum[7] += 1;
                        break;
                    case 73:
                        lettNum[8] += 1;
                        break;
                    case 74:
                        lettNum[9] += 1;
                        break;
                    case 75:
                        lettNum[10] += 1;
                        break;
                    case 76:
                        lettNum[11] += 1;
                        break;
                    case 77:
                        lettNum[12] += 1;
                        break;
                    case 78:
                        lettNum[13] += 1;
                        break;
                    case 79:
                        lettNum[14] += 1;
                        break;
                    case 80:
                        lettNum[15] += 1;
                        break;
                    case 81:
                        lettNum[16] += 1;
                        break;
                    case 82:
                        lettNum[17] += 1;
                        break;
                    case 83:
                        lettNum[18] += 1;
                        break;
                    case 84:
                        lettNum[19] += 1;
                        break;
                    case 85:
                        lettNum[20] += 1;
                        break;
                    case 86:
                        lettNum[21] += 1;
                        break;
                    case 87:
                        lettNum[22] += 1;
                        break;
                    case 88:
                        lettNum[23] += 1;
                        break;
                    case 89:
                        lettNum[24] += 1;
                        break;
                    case 90:
                        lettNum[25] += 1;
                        break;
                    default:
                        break;
                printf("%d", lettNum[counter]);
                counter++;
                }
                
                
            }
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
