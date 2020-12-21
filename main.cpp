#include <iostream>

#include "InputBuffer.h"
#include "Common.h"

int main(int argc, char *argv[]) {
    InputBuffer inputBuffer;
    while (true) {
        inputBuffer.printPrompt();
        inputBuffer.readInput();

        if (inputBuffer.getBuffer()[0] == '.') {
            switch(doMetaCommand(inputBuffer)) {
                case META_COMMAND_SUCCESS:
                    continue;
                case META_COMMAND_UNRECOGNIZED_COMMAND:
                    std::cout << "Unrecognized command " << inputBuffer.getBuffer() << std::endl;
                    continue;
            }
        }

        Statement statement;
        switch(prepareStatement(inputBuffer, statement)) {
            case PREPARE_SUCCESS:
                break;
            case PREPARE_UNRECOGNIZED_STATEMENT:
                std::cout << "Unrecognized keyword at start of '" << inputBuffer.getBuffer() << "'." << std::endl;
                continue;
        }

        executeStatement(statement);
        printf("Executed.\n");
    }
    return 0;
}
