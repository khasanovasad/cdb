#include <stdio.h>

#include "common.h"
#include "input_buffer.h"

typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND,
} meta_command_result;

typedef enum {
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT,
} prepare_result;

typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT,
} statement_type;

typedef struct {
    statement_type type;
} statement;

meta_command_result do_meta_command(input_buffer* ibuffer) {
    if (strcmp(ibuffer->buffer, ".exit") == 0) {
        exit(EXIT_SUCCESS);
    } else {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}

prepare_result prepare_statement(input_buffer* ibuffer, statement* statement) {
    if (strncmp(ibuffer->buffer, "insert", 6) == 0) {
        statement->type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }
    if (strcmp(ibuffer->buffer, "select") == 0) {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }
    return PREPARE_UNRECOGNIZED_STATEMENT;
}

void execute_statement(statement* statement) {
    switch (statement->type) {
        case STATEMENT_INSERT:
            printf("This is where we would do an insert.\n");
            break;
        case STATEMENT_SELECT:
            printf("This is where we would do a select.\n");
            break;
    }
}

int main(int argc, char *argv[]) {
    input_buffer* ibuffer = input_buffer_start();
    while (true) {
        print_prompt();
        read_input(ibuffer);

        if (ibuffer->buffer[0] == '.') {
            switch(do_meta_command(ibuffer)) {
                case META_COMMAND_SUCCESS:
                    continue;
                case META_COMMAND_UNRECOGNIZED_COMMAND:
                    printf("Unrecognized command %s\n", ibuffer->buffer);
                    continue;
            }
        }

        statement statement;
        switch(prepare_statement(ibuffer, &statement)) {
            case PREPARE_SUCCESS:
                break;
            case PREPARE_UNRECOGNIZED_STATEMENT:
                printf("Unrecognized keyword at start of '%s'.\n",
                                    ibuffer->buffer);
                continue;
        }

        execute_statement(&statement);
        printf("Executed.\n");
    }
    input_buffer_finish(ibuffer);
    return 0;
}
