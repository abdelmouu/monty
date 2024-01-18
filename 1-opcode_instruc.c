#include "monty.h"

/**
 * _push - pushes an element onto the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 *
 * Return: no return
 */
void _push(stack_t **doubly, unsigned int cline)
{
	int m;
	int n;

	if (!vglo.arg)
	{
		dprintf(2, "Error: L%u: usage: push integer\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (m = 0; vglo.arg[m] != '\0'; m++)
	{
		if (!isdigit(vglo.arg[m]) && vglo.arg[m] != '-')
		{
			dprintf(2, "Error: L%u: usage: push integer\n", cline);
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
 * _pall - prints all the values in the stack
 *
 * @doubly: the head of the linked list
 * @cline: the line numbers
 * Return: no return expected
 */
void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _pint - it prints the value at the top of the stack
 *
 * @doubly: the head of the linked list
 * @cline: the line number
 *
 * Return: no return expected
 */
void _pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		dprintf(2, "Error: L%u: can't pint, stack empty\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 * _pop -it removes the top element of the stack
 *
 * @doubly: the head of the linked list
 * @cline: the line number
 *
 * Return: no return expected
 */
void _pop(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "Error: L%u: can't pop an empty stack\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}

/**
 * _swap - it swaps the top two elements of the stack
 *
 * @doubly: the head of the linked list
 * @cline: the line number
 *
 * Return: no return expected
 */
void _swap(stack_t **doubly, unsigned int cline)
{
	int i = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "Error: L%u: can't swap, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = *doubly;
	*doubly = (*doubly)->next;
	aux->next = (*doubly)->next;
	aux->prev = *doubly;
	(*doubly)->next = aux;
	(*doubly)->prev = NULL;
}
