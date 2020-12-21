#include "InputBuffer.h"

InputBuffer::InputBuffer() { }

InputBuffer::~InputBuffer() { }

void InputBuffer::PrintPrompt() const { std::cout << "cdb > "; }

void InputBuffer::ReadInput()
{
    std::getline(std::cin, buffer_);
    if (buffer_.empty())
    {
        std::cerr << "Error reading input." << std::endl;
        exit(EXIT_FAILURE);
    }
}

void InputBuffer::SetBuffer(std::string buffer)
{
    this->buffer_ = buffer;
}

std::string InputBuffer::GetBuffer() const
{
    return buffer_;
}
