#ifndef CPPDB_INPUT_BUFFER_H
#define CPPDB_INPUT_BUFFER_H

#include <iostream>
#include <string>
#include <utility>

class InputBuffer {
    public:
        InputBuffer();
        ~InputBuffer();

        void printPrompt() const;
        void readInput();

        void setBuffer(std::string buffer);
        [[nodiscard]] std::string getBuffer() const;

    private:
        std::string buffer_;
};

#endif // CPPDB_INPUT_BUFFER_H
