#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo(int num1, int num2)
{	
	while (num1 != num2)
	{
		if (num1 > num2)
		{
			num1 -= num2;
		}
		else
		{
			if (num1 < num2)
				num2 -= num1;
		}
	}
	
	return num1;
}

int main(int argc, char **argv)
{
	int num1, num2;
	
	if (argc != 3)
	{
		fprintf(stderr, "USAGE: %s <num1> <num2>\n", argv[0]);
		exit(1);
	}
	
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	
	printf("foo(%d, %d) = %d\n", num1, num2, foo(num1, num2));
	
	return 0;
}
