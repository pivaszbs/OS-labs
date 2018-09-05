#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct node
{
	int value;
	struct node *next;
	struct node *prev;
} node_t;

typedef struct list
{
	node_t *head;
	node_t *tail;
	int length;
} list_t;

list_t create_list(int value)
{
	node_t *head = malloc(sizeof(node_t));
	head -> value = value;
	list_t list = {head, head, 1};
	return list;
}

void print_list(list_t l)
{
	node_t *cur = l.head;
	while (cur!=NULL)
	{
		printf("%d ", cur -> value);
		cur = cur -> next;
	}
}

void print_list_rev(list_t l)
{
	node_t *cur = l.tail;
	while (cur!=NULL)
	{
		printf("%d ", cur -> value);
		cur = cur -> prev;
	}	
}

void insert_node(list_t *l, node_t *n, int value)
{
	node_t *new_node = malloc(sizeof(node_t));
	new_node -> value = value;
	new_node -> next = n -> next;
	new_node -> prev = n;
	if (new_node -> next != NULL)
		new_node -> next -> prev = new_node;
	n -> next = new_node;
	if (new_node -> next == NULL)
		l -> tail = new_node;
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
		node -> prev -> next = node -> next;
		node -> next -> prev = node -> prev;
		free(node);
	}
}


int main(int argc, char const *argv[])
{
	list_t list = create_list(4);
	for (int i = 0; i < 10; ++i)
	{
		insert_node(&list, list.head, i);
	}
	print_list_rev(list);
	return 0;
}