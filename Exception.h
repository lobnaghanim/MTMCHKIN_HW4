#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
using namespace std;



class Exception : public std::exception{
public:
//    virtual const char* what() const noexcept = 0;
};
class DeckFileNotFound : public Exception {
public:
    const char* what() const noexcept override {
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public Exception {
private:
    string errorMessage;

public:
    explicit DeckFileFormatError(int lineNumber) {
        errorMessage = "Deck File Error: File format error in line " + to_string(lineNumber);
    }

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};

class DeckFileInvalidSize : public Exception {
public:
    const char* what() const noexcept override {
        return "Deck File Error: Deck size is invalid";
    }
};


#endif