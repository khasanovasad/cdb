#include <iostream>

#include "InputBuffer.h"

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

meta_command_result do_meta_command(const InputBuffer& ibuffer) 
{
    if (ibuffer.GetBuffer() == ".exit") 
        exit(EXIT_SUCCESS);
    else 
        return META_COMMAND_UNRECOGNIZED_COMMAND;
}

prepare_result prepare_statement(const InputBuffer& ibuffer, statement* statement) 
{
    if (ibuffer.GetBuffer().compare(0, 6, "insert") == 0)
    {
        statement->type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }

    if (ibuffer.GetBuffer() == "select")
    {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }
    return PREPARE_UNRECOGNIZED_STATEMENT;
}

void execute_statement(statement* statement) 
{
    switch (statement->type) 
    {
        case STATEMENT_INSERT:
            std::cout << "This is where we would do an insert.\n";
            break;
        case STATEMENT_SELECT:
            std::cout << "This is where we would do an select.\n";
            break;
    }
}

int main(int argc, char *argv[]) 
{
    InputBuffer ibuffer;
    while (true) 
    {
        ibuffer.PrintPrompt();
        ibuffer.ReadInput();

        if (ibuffer.GetBuffer()[0] == '.') 
        {
            switch(do_meta_command(ibuffer)) 
            {
                case META_COMMAND_SUCCESS:
                    continue;
                case META_COMMAND_UNRECOGNIZED_COMMAND:
                    std::cout << "Unrecognized command " << ibuffer.GetBuffer() << std::endl;
                    continue;
            }
        }

        statement statement;
        switch(prepare_statement(ibuffer, &statement)) 
        {
            case PREPARE_SUCCESS:
                break;
            case PREPARE_UNRECOGNIZED_STATEMENT:
                std::cout << "Unrecognized keyword at start of '" << ibuffer.GetBuffer() << "'." << std::endl;
                continue;
        }

        execute_statement(&statement);
        printf("Executed.\n");
    }
    return 0;
}
