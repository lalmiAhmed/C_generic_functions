// C Program to Demonstrate the use of strcmp() function
#include <stdio.h>
#include <string.h>

int main()
{
	// declaring two same string
	char* first_str = "aaa";
	char* second_str = "bac";

	// printing the strings
	printf("First String: %s\n", first_str);
	printf("Second String: %s\n", second_str);

	// printing the return value of the strcmp()
	printf("Return value of strcmp(): %d\n",
		strcmp(first_str, second_str));

	return 0;
}
