#include "monty.h"
/**
 *
 *
 *
 */
void nodeswap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, line_num, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}
/**
 *
 *
 *
 */
void nop(stack_t **stack, unsigned  int line_num)
{
	(void)stack;
	(void)line_num;
}
/**
 *
 *
 */
void node_div(stack_t **stack, unsigned int line_num)
{
	int summat;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, line_num, "div");
	if ((*stack)->n == 0)
		more_error(9, line_num);
	(*stack) = (*stack)->next;
	summat = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = summat;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 *
 *
 *
 *
 *
 */
void node_add(stack_t **stack, unsigned int line_num)
{
	int summat;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, line_num, "add");
	(*stack) = (*stack)->next;
	summat = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = summat;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 *
 *
 *
 *
 */
void node_sub(stack_t **stack, unsigned int line_num)
{
	int summat;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, line_num, "sub");
	(*stack) = (*stack)->next;
	summat = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = summat;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
