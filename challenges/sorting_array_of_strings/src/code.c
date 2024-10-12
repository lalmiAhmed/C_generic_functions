#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    int l =  strlen(a)>strlen(b) ? strlen(a) : strlen(b);
    for(int i=0; i<l; i++) {
        if(strcmp(a+i, b+i)>0) {
            return 1;
        }
        else if (strcmp(a+i, b+i)<0) {
            return 0;
        }
    }
    return 2;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    int l =  strlen(a)>strlen(b) ? strlen(a) : strlen(b);
    for(int i=0; i<l; i++) {
        if(strcmp(a+i, b+i)>0) {
            return 0;
        }
        else if (strcmp(a+i, b+i)<0) {
            return 1;
        }
    }
    return 2;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int d1 = 0, d2 = 0;
    int hash[128] = {0};
    for(int i=0; i<strlen(a); i++) {
        hash[a[i]] = 1;
    }
    for(int i=0; i<128; i++) {
        d1 += hash[i];
    }
    memset(hash, 0, sizeof hash);
    for(int i=0; i<strlen(b); i++) {
        hash[b[i]] = 1;
    }
    for(int i=0; i<128; i++) {
        d2 += hash[i];
    }
    printf("d1: %d\nd2: %d\n", d1, d2);
    if (d1==d2)
        return lexicographic_sort(a, b);
    else
        return  d1>d2 ? 1 : 0;
}

int sort_by_length(const char* a, const char* b) {
    if (strlen(a) == strlen(b))
        return lexicographic_sort(a, b);
    else
        return  strlen(a)>strlen(b) ? 1 : 0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    char *tmp;
    for(int i=0; i<len; i++) {
        for(int j=i+1; j<len; j++) {
            if(cmp_func(*(arr+i), *(arr+j))) {
                tmp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = tmp;
            }
        }
    }
}


int main() 
{
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
    printf("fill in the %d strings: \n", n);
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
    
    printf("the lexicographic_sort: \n");
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    printf("the lexicographic_sort_reverse: \n");
    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    printf("the sort_by_length: \n");
    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    printf("the sort_by_number_of_distinct_characters: \n");
    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}