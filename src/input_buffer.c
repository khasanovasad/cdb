#include "input_buffer.h"

input_buffer* input_buffer_start() {
    input_buffer* new_buffer = (input_buffer*)malloc(sizeof(input_buffer));
    check_alloc(new_buffer, "malloc() failed. Out of memory.");

    new_buffer->buffer = NULL;
    new_buffer->buffer_length = 0;
    new_buffer->input_length = 0;
    return new_buffer;
}

void input_buffer_finish(input_buffer* ibuffer) {
    assert(ibuffer != NULL);

    free(ibuffer->buffer);
    free(ibuffer);
}

void print_prompt() {
    printf("cdb > ");
}

void read_input(input_buffer* ibuffer) {
    assert(ibuffer != NULL);

    size_t bytes_read = getline(&(ibuffer->buffer),
                                &(ibuffer->buffer_length),
                                stdin);
    if (bytes_read <= 0) {
        fprintf(stderr, "Error reading input.\n");
        exit(EXIT_FAILURE);
    }

    ibuffer->input_length = bytes_read - 1;
    ibuffer->buffer[bytes_read - 1] = '\0';
}
