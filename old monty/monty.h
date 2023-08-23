#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>


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

/**
 * struct arg_s - hold variables
 * @stream: File that connects to the content from the files
 * @command: string which will be the line of text read from stream
 * @line_number: for tracking current line number
 * @tokens: used to store tokens from line
 * @instruction: a valid opcode from a line
 * @tokencnt: number of tokens created from line
 * @head: head/top of the stack (doubly linked lists of struct stack_s)
 * @stack_len: tracks the number of nodes in the stack
 * Description: hold variables that will be used
 * in different functions of the project as well as variables
 * that will require memory allocation and freeing
*/
typedef struct arg_s
{
	FILE *stream;
	char *command;
	unsigned int line_number;
	char **tokens;
	int tokencnt;
	instruction_t *instruction;
	stack_t *head;
	int stack_len;
	int stack;
} arg_t;

extern arg_t *arguments;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

int dprintf(int fd, const char *format, ...);
ssize_t getline(char **commandptr, size_t *n, FILE *stream);
FILE *fdopen(int fd, const char *mode);

void malloc_failed(void);
void valid_argument(int argc);
void get_stream(char *fileName);
void close_stream(void);
void free_arguments(void);
void set_arguments(void);
int check_num(char *str);
void free_all_arguments(void);
void delete_stack_node(void);
void tokenize_command(void);
void free_tokens(void);
void run_instruction(void);
void get_instruction(void);
void free_stack(stack_t *head);
#endif
