#include <stdio.h>


int main (){
    FILE * printTest;
    printTest = fopen("text.txt", "r");
    char c;
    char cha = 64;
    int a = cha;
    while(1) {
        c = fgetc(printTest);
        if(feof(printTest)) { 
            break;
        }
        if(c > 90){
            c = c-32; //Takes any character that is a lowercase letter and changes it into a capital letter
        }
        printf("%c", c);
    }

    fclose(printTest);
    printf("\n %d \n", a);
    printf("%c", cha);

    printf("\nProgram terminated.");
    return 0;
}
