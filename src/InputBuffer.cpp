#include "InputBuffer.h"

InputBuffer::InputBuffer() = default;

InputBuffer::~InputBuffer() = default;

void InputBuffer::PrintPrompt() const { std::cout << "cppdb > "; }

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
    this->buffer_ = std::move(buffer);
}

[[nodiscard]] std::string InputBuffer::GetBuffer() const
{
    return buffer_;
}
