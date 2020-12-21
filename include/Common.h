#ifndef CDB_COMMON_H
#define CDB_COMMON_H

#include <iostream>
#include <string>

#include "InputBuffer.h"

enum meta_command_result 
{
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND,
};

enum prepare_result 
{
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT,
};

enum statement_type 
{
    STATEMENT_INSERT,
    STATEMENT_SELECT,
};

typedef struct statement 
{
    statement_type type;
} statement;

meta_command_result do_meta_command(const InputBuffer& ibuffer);
prepare_result prepare_statement(const InputBuffer& ibuffer, statement* statement);
void execute_statement(statement* statement);

#endif // CDB_COMMON_H 