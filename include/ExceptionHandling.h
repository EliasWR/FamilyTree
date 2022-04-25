#ifndef FAMILYTREE_EXCEPTIONHANDLING_H
#define FAMILYTREE_EXCEPTIONHANDLING_H

#include <iostream>
#include <exception>

class ExceptionHandling : public std::exception {

    virtual const char* what() const throw()
    {
        return "New exception has occurred";
    }

} newException;








#endif //FAMILYTREE_EXCEPTIONHANDLING_H
