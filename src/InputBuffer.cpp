#include "InputBuffer.h"

InputBuffer::InputBuffer() = default;

InputBuffer::~InputBuffer() = default;

void InputBuffer::printPrompt() const { std::cout << "cppdb > "; }

void InputBuffer::readInput() {
    std::getline(std::cin, buffer_);
    if (buffer_.empty()) {
        std::cerr << "Error reading input." << std::endl;
        exit(EXIT_FAILURE);
    }
}

void InputBuffer::setBuffer(std::string buffer) {
    this->buffer_ = std::move(buffer);
}

[[nodiscard]] std::string InputBuffer::getBuffer() const {
    return buffer_;
}
