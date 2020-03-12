#include "lists.h"

/**
 * reverse - reverse the linked list
 * @head: pointer to the linked list
 *
 * Return: reversed linked list
 */
void *reverse(listint_t *head)
{
	listint_t *nextnode = head;
	listint_t *current = head;
	listint_t *prevnode = NULL;

	while (nextnode)
	{
		nextnode = current->next;
		current->next = prevnode;
		prevnode = current;
		current = nextnode;
	}
	return (prevnode);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the linked list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *newnode, *left, *right, *data;

	right = *head;
	newnode = *head;
	left = *head;
	while (right && left->next && left->next->next)
	{
		newnode = newnode->next;
		left = left->next->next;
	}
	data = reverse(newnode);
	while (data && right)
	{
		if (data->n != right->n)
			return (0);
		if (data->n == right->n)
			return (1);
		data = data->next;
		right = right->next;
	}
}
