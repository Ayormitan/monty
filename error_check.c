#include "monty.h"
/**
 *
 *
 *
 *
 *
 *
 */
void error(int error_code, ...)
{
	va_list args;
	char *op;
	int lg_num;

	va_start(args, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Cant't open file %s\n", va_arg(args, char *));
			break;
		case 3:
			lg_num = va_arg(args, int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", lg_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	freenodes();
	exit(EXIT_FAILURE);
}
/**
 *
 *
 *
 *
 *
 *
 *
 */
void more_error(int error_code, ...)
{
	va_list args;
	char *op;
	int lg_num;

	va_start(args, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
			break;
		case 8:
			lg_num = va_arg(args, unsigned int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", lg_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	freenodes();
	exit(EXIT_FAILURE);
}
/**
 *
 *
 *
 *
 *
 *
 */
void str_error(int error_code, ...)
{
	va_list args;
	int lg_num;

	va_start(args, error_code);
	lg_num = va_arg(args, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", lg_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", lg_num);
			break;
		default:
			break;
	}
	freenodes();
	exit(EXIT_FAILURE);
}
