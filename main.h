#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* Flag Modifier Macros */
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define NEG_FLAG ((flags >> 4) & 1)

/* Length Modifier Macros */
#define SHORT 1
#define LONG 2

/**
 * struct buffer_s - A new type defining a buffer struct.
 * @buffer: A pointer to a character array.
 * @start: A pointer to the start of buffer.
 * @len: The length of the string stored in buffer.
 */
typedef struct ourBuffer
{
	char *buffer;
	char *start;
	unsigned int len;
} ourBuffer;

/**
 * struct converter_s - A new type defining a converter struct.
 * @specifier: A character representing a conversion specifier.
 * @func: A pointer to a conversion function corresponding to specifier.
 */
typedef struct converter_s
{
	unsigned char specifier;
	unsigned int (*func)(va_list, ourBuffer *,
			unsigned char, int, int, unsigned char);
} converter_t;

/**
 * struct flag_s - A new type defining a flags struct.
 * @flag: A character representing a flag.
 * @value: The integer value of the flag.
 */
typedef struct flag_s
{
	unsigned char flag;
	unsigned char value;
} flag_t;

int _printf(const char *format, ...);

/* Converters */
unsigned int convert_c(va_list args, ourBuffer *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_s(va_list args, ourBuffer *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_percent(va_list args, ourBuffer *output,
		unsigned char flags, int wid, int prec, unsigned char len);

/* Handlers */
unsigned char handle_flags(const char *flags, char *index);
int handle_width(va_list args, const char *modifier, char *index);
unsigned int (*handle_specifiers(const char *specifier))(va_list, ourBuffer *,
		unsigned char, int, int, unsigned char);

/* Modifiers */
unsigned int print_width(ourBuffer *output, unsigned int printed,
		unsigned char flags, int wid);
unsigned int print_string_width(ourBuffer *output,
		unsigned char flags, int wid, int prec, int size);
unsigned int print_neg_width(ourBuffer *output, unsigned int printed,
		unsigned char flags, int wid);

/* Memory Mananger */
ourBuffer *init_buffer(void);
void free_buffer(ourBuffer *output);
unsigned int _memcpy(ourBuffer *output, const char *src, unsigned int n);

#endif /* MAIN_H */
