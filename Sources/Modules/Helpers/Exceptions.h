#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

class NotImplementedException : public std::runtime_error
{
public:
    NotImplementedException() : runtime_error("Method not implemented") {}
};

class InvalidLengthException : public std::runtime_error
{
public:
    InvalidLengthException() : runtime_error("Object length is invalid (too long or too short)") {}
};

#endif //EXCEPTIONS_H
