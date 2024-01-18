#include "monty.h"
/**
 * add_dnodeint_end - Appends a node at the end of a doubly linked list.
 * @head: Pointer to the first node of the linked list.
 * @n: Data to be stored in the new node.
 * Return: Pointer to the updated doubly linked list.
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tmp, *ux;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	ux = *head;
	while (ux->next)
		ux = ux->next;
	tmp->next = ux->next;
	tmp->prev = ux;
	ux->next = tmp;
	return (ux->next);
}

/**
 * add_dnodeint - Inserts a node at the beginning of a doubly linked list.
 * @head: Pointer to the first node of the linked list.
 * @n: Data to be stored in the new node.
 * Return: Pointer to the updated doubly linked list.
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *tmp;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	(*head)->prev = tmp;
	tmp->next = (*head);
	tmp->prev = NULL;
	*head = tmp;
	return (*head);
}

/**
 * free_dlistint - Frees a doubly linked list.
 *
 * @head: Pointer to the head of the list.
 * Return: No return value.
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
