#include "monty.h"
/**
 *
 *
 *
 */
void string_prints(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	temp = *stack;
	while (temp != NULL)
	{
		ascii = temp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->next;
	}
	printf("\n");
}
/**
 *
 *
 *
 */
void char_print(stack_t **stack, unsigned int line_num)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		str_error(11, line_num);
	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		str_error(10, line_num);
	printf("%c\n", ascii);
}
/**
 *
 *
 */
void rot1(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
/**
 *
 *
 *
 *
 *
 *
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
