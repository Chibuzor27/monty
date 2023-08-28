#ifndef MONTY_H
#define MONTY_H
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
	int (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct ops_s - opcodes
 * @opcode: the opcode
 * @line_number: the line number
 */
typedef struct ops_s
{
	char *opcode;
	int line_number;
	struct ops_s *next;
} ops_t;

int _isdigit(char *text);
int _atoi(char *str);
int push(stack_t **stack, char *, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
int _pall(stack_t **stack, unsigned int line_number);
int _pint(stack_t **stack, unsigned int line_number);
int _pop(stack_t **stack, unsigned int line_number);
int _swap(stack_t **stack, unsigned int line_number);
int _add(stack_t **stack, unsigned int line_number);
int _sub(stack_t **stack, unsigned int line_number);
int _div(stack_t **stack, unsigned int line_number);
int _mul(stack_t **stack, unsigned int line_number);
int _mod(stack_t **stack, unsigned int line_number);
int _nop(stack_t **stack, unsigned int line_number);
/*
void (*get_op(char *op, unsigned int))(stack_t **, unsigned int);
*/
int (*get_op(char *op, unsigned int ln))(stack_t **, unsigned int);
ops_t *read_ops(char *line, int *n, ops_t **, ops_t **);
int _puts(int fd, char *s);
int _putchar(int fd, char c);
int _putn(int fd, unsigned int n);
ops_t *read_textfile(const char *, size_t);
ops_t *readfile(char *filename, size_t limit);
void free_stack(stack_t **stack);
void free_ops(ops_t **ops);

#endif
