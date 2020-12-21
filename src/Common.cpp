#include "Common.h"

meta_command_result doMetaCommand(const InputBuffer& inputBuffer) {
    if (inputBuffer.getBuffer() == ".exit")
        exit(EXIT_SUCCESS);
    else 
        return META_COMMAND_UNRECOGNIZED_COMMAND;
}

prepare_result prepareStatement(const InputBuffer& inputBuffer, Statement& statement) {
    if (inputBuffer.getBuffer().compare(0, 6, "insert") == 0) {
        statement.type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }

    if (inputBuffer.getBuffer() == "select") {
        statement.type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }
    return PREPARE_UNRECOGNIZED_STATEMENT;
}

void executeStatement(const Statement& statement) {
    switch (statement.type) {
        case STATEMENT_INSERT:
            std::cout << "This is where we would do an insert.\n";
            break;
        case STATEMENT_SELECT:
            std::cout << "This is where we would do an select.\n";
            break;
    }
}