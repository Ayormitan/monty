#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

int main(int argc, char *argv[]);
stack_t *make_node(int n);
void add2queue(stack_t **new_node, __attribute__((unused))unsigned int ln);
void freenodes(void);

void err(int error_code, ...);
void more_error(int error_code, ...);
void str_error(int error_code, ...);
void nodeswap(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned  int line_num);
void node_div(stack_t **stack, unsigned int line_num);
void node_add(stack_t **stack, unsigned int line_num);
void node_sub(stack_t **stack, unsigned int line_num);
void string_prints(stack_t **stack, __attribute__((unused))unsigned int ln);
void char_print(stack_t **stack, unsigned int line_num);
void rot1(stack_t **stack, __attribute__((unused))unsigned int ln);
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln);

void file_opener(char *file_name);
int line_parser(char *buff, int line_num, int format);
void mon_read_file(FILE *fd);
void find_my_func(char *opcode, char *val, int en, int format);
void call_my_func(op_func, char *op, char *val, int en, int format);

void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int en); 
void print_my_stack(stack_t **stack, unsigned int line_num);
void pop_on_top(stack_t **stack, unsigned int line_num);
void top_print(stack_t **stack, unsigned int line_num);
void multi_nodes(stack_t **stack, unsigned int line_num);
void mode_node(stack_t **stack, unsigned int line_num); 
#endif
