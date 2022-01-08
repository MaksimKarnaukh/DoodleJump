

#ifndef DOODLEJUMP_LOADFILEEXCEPTION_H
#define DOODLEJUMP_LOADFILEEXCEPTION_H

#include <exception>
#include <iostream>
#include <string>

class LoadFileException : public std::runtime_error
{
public:
        LoadFileException(const std::string& s) : std::runtime_error(s) {}
};

#endif // DOODLEJUMP_LOADFILEEXCEPTION_H
