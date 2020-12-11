#include <stdio.h>

#include "common.h"
#include "input_buffer.h"

int main(int argc, char *argv[]) {
    input_buffer* ibuffer = input_buffer_start();
    while (true) {
        print_prompt();
        read_input(ibuffer);

        if (strcmp(ibuffer->buffer, ".exit") == 0) {
            input_buffer_finish(ibuffer);
            exit(EXIT_SUCCESS);
        } else {
            printf("Unrecognized command %s.\n", ibuffer->buffer);
        }
    }
    return 0;
}
