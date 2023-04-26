#include "Exception.h"

Exception::Exception(const std::string& message) : std::out_of_range(message){
    Exception::message = message;
};