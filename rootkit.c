#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_t
{
	struct node_t *next;
	int            num;
	char          *str;
};

int find_rootkit(struct node_t *node)
{
	if (node == NULL)
		return -1;
	
	do
	{
		if (node->num == 1337 && strcmp(node->str, "h4x0r") == 0)
			return 1;
	}
	while ((node = node->next) != NULL);
	
	return 0;
}

struct node_t *alloc_task(char *str, int num, struct node_t *next)
{
	struct node_t *node = malloc(sizeof(struct node_t));
	
	node->str  = malloc(strlen(str) + 1);
	strcpy(node->str, str);
	node->num  = num;
	node->next = next;
	
	return node;
}

int main(int argc, char **argv)
{
	char           str[64];
	int            num, rk;
	struct node_t *node = NULL;
	
	while (scanf("%s %d", str, &num) == 2)
		node = alloc_task(str, num, node);
	
	rk = find_rootkit(node);
	
	printf("find_rootkit() = %d\n", rk);
	
	return 0;
}