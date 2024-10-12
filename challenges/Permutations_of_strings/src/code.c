#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
    int i, j;

    // Find the largest index i such that s[i] < s[i + 1]
    for (i = n - 2; i >= 0; i--) {
        if (strcmp(s[i], s[i + 1]) < 0) {
            break;
        }
    }

    // If there is no such index, this is the last permutation
    if (i < 0) {
        return 0;
    }

    // Find the largest index j such that s[j] > s[i]
    for (j = n - 1; j > i; j--) {
        if (strcmp(s[j], s[i]) > 0) {
            break;
        }
    }

    // Swap s[i] and s[j]
    char *temp = s[i];
    s[i] = s[j];
    s[j] = temp;

    // Reverse the order of the elements after i
    for (int l = i + 1, r = n - 1; l < r; l++, r--) {
        char *temp = s[l];
        s[l] = s[r];
        s[r] = temp;
    }

    return 1;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}