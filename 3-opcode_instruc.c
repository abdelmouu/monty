#include "monty.h"

/**
 * _div - it divides the 2nd element of the stack by the top.
 *
 * @doubly: the head of the linked list
 * @cline: the line number;
 *
 * Return: no return expected
 */
void _div(stack_t **doubly, unsigned int cline)
{
	int i = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n /= (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _mul - multiplies the top element of the stack to the 2nd top element
 *
 * @doubly: the head of the linked list
 * @cline: the line number;
 *
 * Return: no return expected
 */
void _mul(stack_t **doubly, unsigned int cline)
{
	int i = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n *= (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _mod - computes the rest of the division of the 2nd element
 * by the top element of the stack
 *
 * @doubly: the head of the linked list
 * @cline: the line number;
 *
 * Return: no return expected
 */
void _mod(stack_t **doubly, unsigned int cline)
{
	int i = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n %= (*doubly)->n;
	_pop(doubly, cline);
}
/**
 * _pchar - print the char value of the 1st element
 *
 * @doubly: the head of the linked list
 * @cline: the line number;
 *
 * Return: no return expected
 */
void _pchar(stack_t **doubly, unsigned int cline)
{
	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, the value is out of range\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*doubly)->n);
}

/**
 * _pstr - it prints the string of the stack
 *
 * @doubly: the head of the linked list
 * @cline: the line number;
 *
 * Return: no return expected
 */
void _pstr(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}
