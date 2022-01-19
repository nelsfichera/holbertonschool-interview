/**
 * is_palindrome - checks if a singly linked list is a plaindrome
 * @head: pointer to head of link list
 * Return: 0 if not plaindrome, 1 if palindrome
 * &empty string = palindrome .
 */
#include "lists.h"

int is_palindrome(listint_t **head)
{
	listint_t *start = *head, *length = *head;
	listint_t *end = *head, *restart = *head;
	int len = 0, i = 0, j;

	if (!length)
		return (1);
	while (length)
	{
		len++;
		length = length->next;
	}
	while (i < len / 2)
	{
		j = i;
		while (j < len - 1)
		{
			end = end->next;
			j++;
		}
		if (start->n != end->n)
			return (0);
		end = restart;
		start = start->next;
		i++;
	}
	return (1);
}
