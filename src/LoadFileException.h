//
// Created by centu on 25/12/2021.
//

#ifndef DOODLEJUMP_LOADFILEEXCEPTION_H
#define DOODLEJUMP_LOADFILEEXCEPTION_H

#include <exception>
#include <string>
#include <iostream>

//class LoadFileException: public std::exception {
//
//    std::string msg;
//
//public:
//
//    LoadFileException(const std::string& _msg) : msg(_msg) {}
//
//    const char* what() const noexcept override {
//        return msg.c_str();
//    }
//};

class LoadFileException: public std::runtime_error {
public:
    LoadFileException(const std::string& s): std::runtime_error(s) {}
};

#endif //DOODLEJUMP_LOADFILEEXCEPTION_H
