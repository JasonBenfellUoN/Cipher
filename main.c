#include <stdio.h>


int main (){
    int c;
    FILE * printTest;
    printTest = fopen("text.txt", "r");
    while(1) {
        c = fgetc(printTest);
        if(feof(printTest)) { 
            break;
        }
        printf("%c", c);
    }

    fclose(printTest);
    printf("\nProgram terminated.");
    return 0;
}
