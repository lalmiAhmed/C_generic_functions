#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;


double get_area (triangle tr) {
    float p = (tr.a+tr.b+tr.c)/2.0;
    return sqrtf(p*(p-tr.a)*(p-tr.b)*(p-tr.c));
}

void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    triangle temp;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(get_area(tr[i])>get_area(tr[j])) {
               temp = tr[i];
               tr[i] = tr[j];
               tr[j] = temp;
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	printf("the result: \n");
	for (int i = 0; i < n; i++) {
		printf("%d %d %d %f\n", tr[i].a, tr[i].b, tr[i].c, get_area(tr[i]));
	}
	return 0;
}
