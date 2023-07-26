#include "shell.h"

/**
 * adnd_nod - adds at the beginning of the list a node .
 * @head: head adresse pointered to the node
 * @strr: field of the node (str)
 * @num: Histoire of node index's .
 * Return: len of linked list
 */
list_s *adnd_nod(list_s **head, const char *strr, int num)
{
list_s *new__head;

if (!head)
	return (NULL);
new__head = malloc(sizeof(list_s));
if (!new__head)
	return (NULL);
_memfilsetl((void *)new__head, 0, sizeof(list_s));
new__head->num = num;
if (strr)
{
	new__head->str = _strtprp(strr);
	if (!new__head->str)
	{
		free(new__head);
		return (NULL);
	}
}
new__head->next = *head;
*head = new__head;
return (new__head);
}


/**
 * nodd_add_end - adds at the final of the list a node .
 * @head: head adresse pointered to the node
 * @str: field of the node (str).
 * @num: Histoire of node index's .
 * Return: len of linked list
 */
list_s *add_node_end(list_s **head, const char *strr, int num)
{
list_s *new__node, *nod;

if (!head)
	return (NULL);

nod = *head;
new__node = malloc(sizeof(list_s));
if (!new__node)
	return (NULL);
_memfilsetl((void *)new__node, 0, sizeof(list_s));
new__node->num = num;
if (strr)
{
	new__node->str = _strtprp(strr);
	if (!new__node->str)
	{
		free(new__node);
		return (NULL);
	}
}
if (nod)
{
	while (nod->next)
		nod = nod->next;
	nod->next = new__node;
}
else
	*head = new__node;
return (new__node);
}

/**
 * prin_li_stt - the only printed is the strr elem of a list_s (linked-list).
 * @h: head pointered to the begin  first case node.
 * Return: len of linked list
 */
size_t prin_li_stt(const list_s *h)
{
	size_t d = 0;

	while (h)
	{
		_puutss(h->str ? h->str : "(nil)");
		_puutss("\n");
		h = h->next;
		d++;
	}
	return (d);
}

/**
 * rmove_node_at_index - removees the node at index
 * @head: the address of an pointered to initial node's .
 * @index: the num of node to removed .
 * Return: 1 correct, else 0 .
 */
int rmove_node_at_index(list_s **head, unsigned int index)
{
list_s *nod, *prev__node;
unsigned int d = 0;

if (!head || !*head)
	return (0);

if (!index)
{
	nod = *head;
	*head = (*head)->next;
	free(nod->str);
	free(nod);
	return (1);
}
nod = *head;
while (nod)
{
	if (d == index)
	{
		prev__node->next = nod->next;
		free(nod->str);
		free(nod);
		return (1);
	}
d++;
	prev__node = nod;
	nod = nod->next;
}
return (0);
}

/**
 * frfee_lis - delete all elements(nodes) of the linked-list
 * @head_ptr: adress of the head pointered.
 * Return: nothing .
 */
void frfee_lis(list_s **head_ptr)
{
list_s *nod, *next__nod, *head;

if (!head_ptr || !*head_ptr)
return;
head = *head_ptr;
nod = head;
while (nod)
{
next__nod = nod->next;
free(nod->str);
free(nod);
nod = next__nod;
}
*head_ptr = NULL;
}

