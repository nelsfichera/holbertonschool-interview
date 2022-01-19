#include "lists.h"
/**
 * is_palindrome - checks if a singly linked list is a plaindrome
 * @head: pointer to head of link list
 * Return: 0 if not plaindrome, 1 if palindrome
 * &empty string = palindrome .
 */

int is_palindrome(listint_t **head)
{
	listint_t *start = *head, *length = *head;
	listint_t *end = *head, *restart = *head;
	int len = 0, i = 0, j;
    /* return true on 0 length */
	if (!length)
		return (1);
    /* iterate through list */
	while (length)
	{
		len++;
		length = length->next;
	}
    /*
     * compare lists by moving i & j,
     *  using start and end
     */
	while (i < len / 2)
	{
		j = i;
		while (j < len - 1)
		{
			end = end->next;
			j++;
		}
		/* return 0 on failure*/
		if (start->n != end->n)
			return (0);
		/* move end back to beginning of list */
		end = restart;
		start = start->next;
		i++;
	}
	return (1);
}
