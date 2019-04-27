#include <stdio.h>
char rotation(char c, int key); 

int main (){
    FILE * printTest;
    FILE * encodeMeRotation; //Points to a file under the name "encodeMeRotation"
    FILE * decodeMeRotation;
    FILE * decodeMeKnownSubs;
    FILE * substitutionKeys;
    FILE * encodeMeSubs;
    printTest = fopen("text.txt", "r"); 
    encodeMeRotation = fopen("encodeMeRotation", "r"); //Opens the file "encodeMeRotation" for "reading" (r)
    decodeMeRotation = fopen("decodeMeRotation", "r");
    decodeMeKnownSubs = fopen("decodeMeKnownSubs", "r");
    substitutionKeys = fopen("substitutionKeys", "r");
    encodeMeSubs = fopen("encodeMeSubs", "r");
    int choice = 0; //Initialises variables.
    int testCounter = 0;
    int n;
    char c;
    char cha = 64;
    int a = cha;
    int lettNum[26] = {0};
    int alphhFreq[10] = {69, 84, 65, 79, 73, 78, 83, 82, 72, 68};
    int stdAlphabet[26] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90}; //Initialises an array that contains the ASCII codes for each letter of the alphabet.
    int counter = 0;
    printf("Welcome to the Cipher Program, version: 1.3\n"); // These three lines print introductions to the programs, and its specifications
    printf("Please provide an input: \n1 for encryption, 2 for decryption.\n"); // and they provide user-friendly instructions
    printf("Currently, only rotation ciphers are implemented.\n"); // and what it is capable of.
    scanf("%d", &choice);
    int i = 0;
    if(choice == 1){ //Simple UI choice for selection of function.
        printf("Please provide an input from -25 to 25\nIncluding 0 will cause no encryption.\n");
        int key;
        scanf("%d", &key); //Takes the input of the user and makes it the key for the rotation cipher.
        if(25 < key || -25 > key){ //Checks if the key is outside of the acceptable range, if not, rejects the input.
            printf("Invalid input.\n");
            return;
        }
        printf("Your key is: %d\n", key); //Outputs a confirmation - useful to see if the program somehow returned something wrong.

            
        while(!feof(encodeMeRotation)){ //While the file end has NOT been reached.
            c = fgetc(encodeMeRotation); //Get a single character from the file, and store it in the variable 'c'.
                
            if(c > 90){ //Detects lowercase letters (all ASCII lowercase letters are greater than 90)
                c = c-32; //Takes any character that is a lowercase letter and changes it into a capital letter (the difference between an ASCII lower and upper case is exactly 32)
            }

            if ((c < 65) || (c> 90)) { 
                printf("%d %c %c\n", i, c, c); //Checks characters are within the upper-case ASCII range, and if so, prints them.
            }else{
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
            }else{
                i++;
                printf("%d %c", i, c);
                c += key;
                if(c < 65){
                    c = 155 - c;
                }else if(c > 90){
                    c = c - 26;
                }
                printf(" %c\n", c);     
            }
        }
    
    }else if(choice ==3){
        int decoderCounter = 0; //Variable initisalisation
        int someTempValue = 0;
        int charHunter = 0;
        int keymaker = 0;
        char lovelyLetter;
        char toChange;
        int key[26];
        while(keymaker < 26){ //Runs through the whole array
            key[keymaker] = fgetc(substitutionKeys); //Places a character in each spot of the array.
            keymaker++;
        }
        while(!feof(decodeMeKnownSubs)){ //While the file is NOT at the end.
            lovelyLetter = fgetc(decodeMeKnownSubs);
            someTempValue++;
            int i = 0;

            while(i < 26){
                if(lovelyLetter == key[i]) //If the letter is the same as the key, break out of the while loop.
                   break;
                i++; //Increase i. Due to the loop, i should never be above 26.            
            }         

                        
                        
             if (i < 26) //If the key is within the alphabet. 
            {
      //          printf("%c", stdAlphabet[i]);
                printf("%c", stdAlphabet[i]); //Print the alphabet character that matches the key.
            } else {
                printf("%c", lovelyLetter); //Else, the character is clearly not an alphabetic character, and must be punctuation. In that case, print it normally.
            }


                
            
        }
    }else if(choice == 4){ //This is, in essence, identifcal to the decryption algorithm, just switched to encrypt via changing the standard alphabet to the key, instead of the key to the standard alphabet.
        int key[26];
        int keymaker = 0;
        int charac;
        int counter = 0;
        int someTempValue = 0;
        while(keymaker < 26){
            key[keymaker] = fgetc(substitutionKeys);
            keymaker++;
        }
        while(!feof(encodeMeSubs)){
            charac = fgetc(encodeMeSubs);
            if(charac > 90){ 
                charac = charac-32;
            }
            someTempValue++;
            int i = 0;
            while(i < 26){
                if(charac == stdAlphabet[i]) //If the character is the same as the standard alphabet, break.
                    break;
                i++;
            }
            
            
            if(i < 26){
                printf("%c", key[i]); //Print the encrypted character that is in the same place as the unencrypted character.
            } else {
                printf("%c", charac); //If the while loop went through 26 cycles, it is not a character, and therefore is punctuation or grammar. Therefore, print it without change.
            }
        }
    



            




        
    }else if(choice == 9){
            while(!feof(decodeMeRotation)){ //This while loop continues until the file has reached its end.
                c = fgetc(decodeMeRotation);
                if(c > 90){ //Changes lowercase letters to capitals.
                    c = c-32;
                }
                switch(c){ //A switch statement that runs through each letter and increments by one each time a letter is found.
                    case 65: 
                        lettNum[0] += 1;
                        counter++;
                        printf("%d", lettNum[0]);
                        break;
                    case 66:
                        lettNum[1] += 1;
                        counter++;
                        printf("%d", lettNum[1]);
                        break;
                    case 67:
                        lettNum[2] += 1;
                        counter++;
                        printf("%d", lettNum[2]);
                        break;
                    case 68:
                        lettNum[3] += 1;
                        counter++;
                        printf("%d", lettNum[3]);
                        break;
                    case 69:
                        lettNum[4] += 1;
                        counter++;
                        printf("%d", lettNum[4]);
                        break;
                    case 70:
                        lettNum[5] += 1;
                        counter++;
                        printf("%d", lettNum[5]);
                        break;
                    case 71:
                        lettNum[6] += 1;
                        counter++;
                        printf("%d", lettNum[6]);
                        break;
                    case 72:
                        lettNum[7] += 1;
                        counter++;
                        printf("%d", lettNum[7]);
                        break;
                    case 73:
                        lettNum[8] += 1;
                        counter++;
                        printf("%d", lettNum[8]);
                        break;
                    case 74:
                        lettNum[9] += 1;
                        counter++;
                        printf("%d", lettNum[9]);
                        break;
                    case 75:
                        lettNum[10] += 1;
                        counter++;
                        printf("%d", lettNum[10]);
                        break;
                    case 76:
                        lettNum[11] += 1;
                        counter++;
                        printf("%d", lettNum[11]);
                        break;
                    case 77:
                        lettNum[12] += 1;
                        counter++;
                        printf("%d", lettNum[12]);
                        break;
                    case 78:
                        lettNum[13] += 1;
                        counter++;
                        printf("%d", lettNum[13]);
                        break;
                    case 79:
                        lettNum[14] += 1;
                        counter++;
                        printf("%d", lettNum[14]);
                        break;
                    case 80:
                        lettNum[15] += 1;
                        counter++;
                        printf("%d", lettNum[15]);
                        break;
                    case 81:
                        lettNum[16] += 1;
                        counter++;
                        printf("%d", lettNum[16]);
                        break;
                    case 82:
                        lettNum[17] += 1;
                        counter++;
                        printf("%d", lettNum[17]);
                        break;
                    case 83:
                        lettNum[18] += 1;
                        counter++;
                        printf("%d", lettNum[18]);
                        break;
                    case 84:
                        lettNum[19] += 1;
                        counter++;
                        printf("%d", lettNum[19]);
                        break;
                    case 85:
                        lettNum[20] += 1;
                        counter++;
                        printf("%d", lettNum[20]);
                        break;
                    case 86:
                        lettNum[21] += 1;
                        counter++;
                        printf("%d", lettNum[21]);
                        break;
                    case 87:
                        lettNum[22] += 1;
                        counter++;
                        printf("%d", lettNum[22]);
                        break;
                    case 88:
                        lettNum[23] += 1;
                        counter++;
                        printf("%d", lettNum[23]);
                        break;
                    case 89:
                        lettNum[24] += 1;
                        counter++;
                        printf("%d", lettNum[24]);
                        break;
                    case 90:
                        lettNum[25] += 1;
                        counter++;
                        printf("%d", lettNum[25]);
                        break;
                    default:
                        counter++;
                        break;
                } 
                
                
            }
        
            testCounter++;
            int replacerNum;
            int arrayCounter = 0;
            int toBecomeE = 0;
            while(arrayCounter < 26){
                if(lettNum[arrayCounter])
                    toBecomeE = arrayCounter;
                    printf("Array Counter: %d toBecomeE: %d\n", arrayCounter, toBecomeE);
                    arrayCounter++;
                    replacerNum = stdAlphabet[toBecomeE];
                    
                }
            rewind(decodeMeRotation);
            while(!feof(decodeMeRotation)){
                c = fgetc(decodeMeRotation);
                if(c > 90){ //Detects lowercase letters (all ASCII lowercase letters are greater than 90)
            c = c-32; //Takes any character that is a lowercase letter and changes it into a capital letter (the difference between an ASCII lower and upper case is exactly 32)
        }
                if(c == replacerNum){
                    c = stdAlphabet[4];
                }
                printf("%c", c);
            }
       //     rewind(decodeMeRotation);
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
