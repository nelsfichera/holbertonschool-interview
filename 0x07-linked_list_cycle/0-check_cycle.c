#include "lists.h"
/**
 * check_cycle - checks if singly linked list has a cycle
 * @list: pointer to head of list
 * Return: 1 if cycle 0 on failure
 */
int check_cycle(listint_t *list)
{
    /* two pointers*/
	listint_t *ptra, *ptri;

	if (list == NULL)
		return (0);
	ptra = list;
	ptri = list;
	while (ptra && ptri && ptri->next)
	{
		ptra = ptra->next;
		ptri = ptri->next;
		if (ptra == ptri)
			return (1);
	}
	return (0);
}
