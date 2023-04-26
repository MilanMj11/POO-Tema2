#ifndef OOP_EXCEPTION_H
#define OOP_EXCEPTION_H

#include <string>
#include <stdexcept>

class Exception : public std::out_of_range{
private:
    std::string message;
public:
    Exception(const std::string& message);
};


#endif //OOP_EXCEPTION_H
