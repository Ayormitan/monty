#include "monty.h"
/**
 * multi_node - adds first 2 element of a stack
 * @stack: pointer pointer that points to to a top node
 * @line_num: int that represents a line number
 */
void multi_nodes(stack_t **stack, unsigned int line_num)
{
	int total;

	if (stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "multi");

	(*stack) = (*stack)->next;
	total = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mode-node - sums the first 2 element to the stack
 * @line_num: int that represents the line number of opcode
 * @stack: pointer pointer that points to top node
 */
void mode_node(stack_t **stack, unsigned int line_num)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "mod");

	if ((*stack)->n == 0)
		more_err(9, line_num);
	(*stack) = (*stack)->next;
	total = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
