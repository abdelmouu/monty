#include "monty.h"

/**
 * _queue - sets the format of the data to a queue (FIFO)
 *
 * @doubly: the head of the linked list
 * @cline: the line number;
 *
 * Return: no return expected
 */
void _queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 0;
}

/**
 * _stack - sets the format fo the data to a stack (LIFO)
 *
 * @doubly: the head of the linked list
 * @cline: the line number;
 *
 * Return: no return expected
 */
void _stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 1;
}

/**
 * _add - adds the top two elements of the stack
 *
 * @doubly: the head of the linked list
 * @cline: the line number;
 *
 * Return: no return expected
 */
void _add(stack_t **doubly, unsigned int cline)
{
	int i = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _sub - it subtracts the top element from the second top element of the stack
 *
 * @doubly: the head of the linked list
 * @cline: the line number;
 *
 * Return: no return expected
 */
void _sub(stack_t **doubly, unsigned int cline)
{
	int i = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n -= (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _nop - doesn't serve anythinhg
 *
 * @doubly: the head of the linked list
 * @cline: the line number;
 *
 * Return: no return expected
 */
void _nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}
