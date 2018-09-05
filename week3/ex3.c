#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct node
{
	int value;
	struct node *next;
} node_t;

typedef struct list
{
	node_t *head;
	int length;
} list_t;

list_t create_list(int value)
{
	node_t *head = malloc(sizeof(node_t));
	head -> value = value;
	list_t list = {head, 1};
}

void print_list(list_t l)
{
	node_t *cur = l.head;
	while (cur!=NULL)
	{
		printf("%d\n", cur -> value);
		cur = cur -> next;
	}
}

void insert_node(node_t *n, int value)
{
	node_t *new_node = malloc(sizeof(node_t));
	new_node -> value = value;
	new_node -> next = n -> next;
	n -> next = new_node;
}

void delete_node(struct list *l, node_t *node)
{
	if (l-> head == node)
	{
		l -> head = node -> next;
		free(node);
	}
	else
	{
		node_t *cur = l-> head;
		while (cur==NULL)
		{
			if (cur -> next == node)
			{
				cur -> next = node -> next;
				free(node);
			}
			else 
			{
				cur = cur -> next;
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	list_t list = create_list(4);
	for (int i = 0; i < 10; ++i)
	{
		insert_node(list.head, i);
	}
	delete_node(&list, list.head);
	print_list(list);
	return 0;
}