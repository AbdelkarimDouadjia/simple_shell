#include "shell.h"

/**
 * liss_lengs - give us the size(len) of linked-list
 * @h:  the begin node has been pointered
 * Return: length if the linked-list
 */
size_t liss_lengs(const list_s *h)
{
size_t d = 0;

while (h)
{
	h = h->next;
	d++;
}
return (d);
}

/**
 * liss_to_str - gives us  a list of multiple 
 *		strings using the list->str funct.
 * @head: the begin node has been pointered
 * Return: multiples of strings.
 */
char **liss_to_str(list_s *head)
{
list_s *noe = head;
size_t d = liss_lengs(head), w;
char **strs;
char *str;

if (!head || !d)
return (NULL);
strs = malloc(sizeof(char *) * (d + 1));
if (!strs)
return (NULL);
for (d = 0; noe; noe = noe->next, d++)
{
str = malloc(_stlesn(noe->str) + 1);
if (!str)
{
	for (w = 0; w < d; w++)
		free(strs[w]);
	free(strs);
	return (NULL);
}

str = _stcocp(str, noe->str);
strs[d] = str;
}
strs[d] = NULL;
return (strs);
}


/**
 ** priin_liss - returns all the nodes of a (linked-list) => list_s
 ** @h: the begin node element has been pointered
 ** Return: leng of liked-list
**/
size_t priin_liss(const list_s *h)
{
size_t d = 0;

while (h)
{
_puutss(converr_nuum(h->num, 10, 0));
_puuchir(':');
_puuchir(' ');
_puutss(h->str ? h->str : "(nil)");
_puutss("\n");
h = h->next;
d++;
}
return (d);
}

/**
* start_nodd_wi - Gives an element node to whose string begin with prefix element.
* @noe: elemn of the begin head of linked-list
* @prefix: matching the begin strings.
* @c: will pick char after prefix characteres and will matching it.
* Return: nothing(null) or matching node
*/
list_s *start_nodd_wi(list_s *noe, char *prefix, char c)
{
char *p = NULL;

while (noe)
{
p = strest_wit(noe->str, prefix);
if (p && ((c == -1) || (*p == c)))
	return (noe);
noe = noe->next;
}
return (NULL);
}

/**
 * gitt_index_index - give the index of the node element in linked-list .
 * @head: the begin node has been pointered
 * @noe: elemn of the begin head of linked-list
 * Return: -1 always, otherwise index of the node element .
 */
ssize_t gitt_index_index(list_s *head, list_s *noe)
{
size_t d = 0;

while (head)
{
if (head == noe)
	return (d);
head = head->next;
d++;
}
return (-1);
}

