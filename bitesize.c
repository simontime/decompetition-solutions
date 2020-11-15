#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void win()
{
	printf("How did you get here??\n");
	exit(42);
}

void sum(int argc, char **argv)
{
	int size, num;
	char buf[247];
	
	size = atoi(argv[1]);
	
	printf("SIZE: %d\n", size);
	
	if (size > 247)
	{
		puts("Too long!");
		return;
	}
	
	memset(buf, 0, sizeof(buf));
	
	num = atoi(argv[1]);
	
	memcpy(buf, argv[2], num);
	
	printf("Got: %s\n", buf);
}

int main(int argc, char **argv)
{
	if (argc > 2)
		sum(argc, argv);
	
	return 0;
}