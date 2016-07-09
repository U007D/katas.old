//
// Created by bRad on 7/9/16.
//

#ifndef UTIL_EXCEPTIONS_H
#define UTIL_EXCEPTIONS_H

#include <stdexcept>

class NotImplementedException : public std::logic_error
{
public:
    NotImplementedException();
};

#endif //UTIL_EXCEPTIONS_H
