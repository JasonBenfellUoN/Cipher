#include <stdio.h>

int main (){
    FILE * encodeMeRotation; //Points to a file under the name "encodeMeRotation". This is necessary for the file to be accessed.
    FILE * decodeMeRotation;
    FILE * decodeMeKnownSubs;
    FILE * substitutionKeys;
    FILE * encodeMeSubs;
    FILE * output;
    encodeMeRotation = fopen("encodeMeRotation", "r"); //Opens the file "encodeMeRotation" for "reading" (r).
    decodeMeRotation = fopen("decodeMeRotation", "r");
    decodeMeKnownSubs = fopen("decodeMeKnownSubs", "r");
    substitutionKeys = fopen("substitutionKeys", "r");
    encodeMeSubs = fopen("encodeMeSubs", "r");
    output = fopen("output", "a");
    int choice = 0; //Initialises variables.
    int testCounter = 0;
    int n;
    char c;
    int lettNum[26] = {0};
    int alphhFreq[10] = {69, 84, 65, 79, 73, 78, 83, 82, 72, 68};
    int stdAlphabet[26] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90}; //Initialises an array that contains the ASCII codes for each letter of the alphabet.
    int counter = 0;
    printf("Welcome to the Cipher Program.\n"); // These first two printfs print a user prompt with instructions on how to operate the program.
    printf("Please provide an input: \n1 for rotation encryption, 2 for rotation decryption, 3 for substitution encryption, 4 for substitution decryption.\n");
    scanf("%d", &choice);
    fprintf(output, "\nNEW OUTPUT\n");
    int i = 0;
    if(choice == 1){ //Simple UI choice for selection of function.
        printf("Input will be taken from the input file (encodeMeRotation). \nPlease enter your key is an integer from 0 to 25. \nIf it is 0, there will be no encryption.\n");
        int key;
        scanf("%d", &key); //Takes the input of the user and makes it the key for the rotation cipher.
        if(25 < key || 0 > key){ //Checks if the key is outside of the acceptable range, if not, rejects the input.
            printf("Invalid input.\n");
            return;
        }
        printf("Your key is: %d\n", key); //Outputs a confirmation - useful to see if the program somehow returned something wrong.

            
        while(!feof(encodeMeRotation)){ //While the file end has NOT been reached.
            c = fgetc(encodeMeRotation); //Get a single character from the file, and store it in the variable 'c' so it can be operated on by the program.
                
            if(c > 90){ //Detects lowercase letters (all ASCII lowercase letters are greater than 90)
                c = c-32; //Takes any character that is a lowercase letter and changes it into a capital letter (the difference between an ASCII lower and upper case is exactly 32)
            }

            if ((c < 65) || (c > 90)) { 
                fprintf(output, "%c" , c); //If the character is outside of the upper-case ASCII range, still, it is likely punctuation and should be printed without alteration.
            }else{
                c += key; //Adds the key to the character. Since characters in ASCII are simply numbers that are converted to characters, you can perform addition or subtraction on the characters to manipulate them.
                if(c < 65){ //If the character is outside of the ASCII upper case.
                    c = 155 - c; //Adjusts the value through a simple operation if the character underflows after the first operation, so that it returns to an appropriate value.
                } else if(c > 90){
                    c = c - 26; //Adjusts the value through a simple operation if the character overflows, so that it returns to an appropriate value.
                }
                fprintf(output, "%c", c);     
            }
        }
    
    }else if(choice == 2){ //This is essentially the same as the above, with a few minor changes.
        printf("Input will be taken from the input file (decodeMeRotation).\n Please enter your key is an integer from 0 to 25. \nIf it is 0, there will be no decryption.\n");
        int key;
        scanf("%d", &key);
        printf("Your key is: %d\n", key);
        if(25 < key || 0 > key){
            printf("Invalid input.\n");
        }
            
        while(!feof(decodeMeRotation)){
            c = fgetc(decodeMeRotation);
            if(c > 90){ //Detects lowercase letters (all ASCII lowercase letters are greater than 90)
                c = c-32; //Takes any character that is a lowercase letter and changes it into a capital letter (the difference between an ASCII lower and upper case is exactly 32)
            }
            if ((c < 65) || (c > 90)) {
                fprintf(output, "%c", c);
            }else{
                c = c - key; //Instead of adding, subtract. This is because the cipher is already shifted in one direction (typically addition) so it needs to be subtracted back. 
                if(c < 65){
                    c = c + 26; //Because subtraction is what occurs, the operation must account for underflow, by adding 26 if the integer goes below the upper case ASCII values.
                }else if(c > 90){
                    c = c - 26;
                }
                fprintf(output, "%c", c);     
            }
        }
    
    }else if(choice == 4){
        printf("Key will be taken from the input file (substitutionKey), and written to output file (output).\n"); //Informational prompt to tell the user where the output and input are supplied.
        int decoderCounter = 0; //Variable initisalisation
        int someTempValue = 0;
        int charHunter = 0;
        int keymaker = 0;
        char c;
        char toChange;
        int key[26];
        while(keymaker < 26){ //Runs through the whole array
            key[keymaker] = fgetc(substitutionKeys); //Places a character in each spot of the array.
            keymaker++;
        }
        while(!feof(decodeMeKnownSubs)){ //While the file is NOT at the end.
            c = fgetc(decodeMeKnownSubs); //Grab a single character to be operated on from the file.
            someTempValue++; 
            int i = 0;

            while(i < 26){
                if(c == key[i]) //If the letter is the same as the key, break out of the while loop.
                   break;
                i++; //Increase i. Due to the loop, i should never be above 26.            
            }         

                        
                        
             if (i < 26) //If the key is within the alphabet. 
            {
      //          printf("%c", stdAlphabet[i]);
                fprintf(output, "%c", stdAlphabet[i]); //Print the alphabet character that matches the key.
            } else {
                fprintf(output, "%c", c); //Else, the character is clearly not an alphabetic character, and must be punctuation. In that case, print it normally.
            }


                
            
        }
    }else if(choice == 3){ //This is, in essence, identifcal to the decryption algorithm, just switched to encrypt via changing the standard alphabet to the key, instead of the key to the standard alphabet.
        printf("Key will be taken from the input file (substitutionKey), and written to output file (output).\n");
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
                fprintf(output, "%c", key[i]); //Print the encrypted character that is in the same place as the unencrypted character.
            } else {
                fprintf(output, "%c", charac); //If the while loop went through 26 cycles, it is not a character, and therefore is punctuation or grammar. Therefore, print it without change.
            }
        }
    }else{
        printf("Invalid input.");
    }

        
 /*   }else if(choice == 9){
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
       //     rewind(decodeMeRotation); */

  
    fprintf(output, "\nOUTPUT END\n"); //Prints to a file, telling where one set of outputs have ended. Useful to order the output file after multiple executions of the program.
    printf("\nProgram terminated.\n"); //Prints to the console, a note that the program has been terminated.
    return 0;
}
