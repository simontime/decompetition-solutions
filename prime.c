#include <stdio.h>
#include <stdlib.h>

int is_prime(int n)
{
	int i;
	
	if (n <= 1)
		return 0;
	
	if (n == 2 || n == 3)
		return 1;
	
	if (n % 2 == 0 || n % 3 == 0)
		return 0;
	
	for (i = 5; n > i * i; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return 0;
	}
	
	return 1;
}

int main(int argc, char **argv)
{
	int n;
	
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s <num>\n", argv[0]);
		exit(1);
	}
	
	n = atoi(argv[1]);
	
	printf("is_prime(%d) = %d\n", n, is_prime(n));
	
	return 0;
}
