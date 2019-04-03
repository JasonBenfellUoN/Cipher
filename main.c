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
        printf("%c", c);
    }

    fclose(printTest);
    printf("\n %d \n", a);
    printf("%c", cha);

    printf("\nProgram terminated.");
    return 0;
}
