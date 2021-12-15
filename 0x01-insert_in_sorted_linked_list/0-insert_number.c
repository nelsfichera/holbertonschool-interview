#include "lists.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
* insert_node - insert a node in a singly linked list
* @head: head of the list
* @number: value
* Return: null on failure//new node on success
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = NULL;
	listint_t *current = NULL;

	if (head == NULL)
		return (NULL);
	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	if (current !=NULL)
	{
		if (number < current->n)
		{
			new->next = current;
			*head = new;
			return (new);
		}
		while (current->next != NULL) 
		{
			if (number < current->next->n)
			{
				new->next = current->next;
				current->next = new;
				return (new);
			}
			current = current->next;
		}
		new->next = NULL;
		current->next = new;
		return (new);
	}
	new->next = NULL;
	*head = new;
	return (new);	
}
