#ifndef CPPDB_INPUT_BUFFER_H
#define CPPDB_INPUT_BUFFER_H

#include <iostream>
#include <string>

class InputBuffer
{
    public:
        InputBuffer();
        ~InputBuffer();

        void PrintPrompt() const;
        void ReadInput();

        void SetBuffer(std::string buffer);
        std::string GetBuffer() const;

    private:
        std::string buffer_;
};

#endif // CPPDB_INPUT_BUFFER_H
