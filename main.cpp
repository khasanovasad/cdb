#include <iostream>

#include "InputBuffer.h"
#include "Common.h"

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
