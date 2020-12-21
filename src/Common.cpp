#include "Common.h"

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