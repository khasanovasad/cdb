#ifndef DB_INPUT_BUFFER_H
#define DB_INPUT_BUFFER_H

#include "common.h"

typedef struct input_buffer {
    char* buffer;
    size_t buffer_length;
    size_t input_length;
} input_buffer;

input_buffer*       input_buffer_start      ();
void                input_buffer_finish     (input_buffer* ibuffer);

void                print_prompt            ();
void                read_input              (input_buffer* ibuffer);

#endif // DB_INPUT_BUFFER_H
