#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    // printf("%c", *(s+4));
    // *(s+4) == 'o' ? printf("True") : printf("False");
    //Write your logic to print the tokens of the sentence here.
    int start = 0;
    int f = 0;
    for(int i=0; i< strlen(s)+1; i++) {
        if (*(s+i) == ' ' || *(s+i) == '\0') {
            f ? start++ : start;
            f = 1;
            for(int j=start; j<i; j++) {
                printf("%c", s[j]);
            }
            printf("\n");
            start = i;
        }
        
    }
    return 0;
}