#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n, s;
    scanf("%d", &n);
    int c=0;
  	// Complete the code to print the pattern.
    for(int j=0; j<n; j++) {
        
        for(int i=0; i<n; i++) {
            if(n-i+1 > n-j)
            printf("%d ", n-i);
        }   
        for(int i=2; i<n*2-1-j-c; i++) {
            printf("%d ", n-j);
        }
        c++;
        for(int i=n; i>1; i--) {
            if(n-i+3 > n-j)
            printf("%d ", n-i+2);
        }
        printf("\n");
    }
    c = 0;
    for(int j=n; j>1; j--) {
        
        for(int i=0; i<j-1; i++) {
            if(n-i+1 > n-j)
            printf("%d ", n-i);
        }   
        for(int i=2; i<n-j+3+c; i++) {
            printf("%d ", n-j+2);
        }
        c++;
        for(int i=j; i>1; i--) {
            if(n-i+3 > n-j)
            printf("%d ", n-i+2);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
