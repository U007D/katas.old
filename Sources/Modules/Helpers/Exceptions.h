#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

class NotImplementedException : public std::runtime_error
{
public:
    NotImplementedException() : runtime_error("Method not implemented") {}
};

class OutOfRangeException : public std::runtime_error
{
public:
    OutOfRangeException() : runtime_error("Value out of permitted range") {}
};

#endif // EXCEPTIONS_H
