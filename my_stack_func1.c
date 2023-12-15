#include "monty.h"
/**
 * add_to_stack - adds node to stack
 * @new_node - pointer to new node
 * @en: int represnting line num
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int en)
{
	stack_t *temp;

	if (new_node == NULL || new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}

/**
 * print_my_stack - adds node to stack
 * @line_num: line number
 * @stack: pointer pointer that points to top node
 */
void print_my_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	(void) line_num;
	if (stack == NULL)
	{
		exit(EXIT_FAILURE);
	}
	temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop_on_top - adds node to the stack
 * @line_num: int represneting ine number
 * @stack: pointer pointer that points to top node
 */
void pop_on_top(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_num);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = next;
	free(temp);
}

/**
 * top_print - prints top node of stack
 * @stack: pointer pointer that points to top node
 * @line_num: int representing line numbe
 */
void top_print(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_num);
	printf("%d\n", (*stack)->n);
}
