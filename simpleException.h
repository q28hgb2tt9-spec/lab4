#ifndef SIMPLE_EXCEPTION_H
#define SIMPLE_EXCEPTION_H

#include <exception>
#include <string>

class simpleException : public std::exception {
private:
    std::string message;

public:
    explicit simpleException(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif
