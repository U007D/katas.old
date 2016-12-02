#ifndef NOT_IMPLEMENTED_EXCEPTION_H
#define NOT_IMPLEMENTED_EXCEPTION_H

#include <stdexcept>

class NotImplementedException : public std::runtime_error
{
public:
	NotImplementedException() : runtime_error("Method not implemented") {}
};

#endif // NOT_IMPLEMENTED_EXCEPTION_H
