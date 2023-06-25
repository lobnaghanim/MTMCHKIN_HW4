#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
using namespace std;

#include <stdexcept>

class Exception{
public:
    virtual string what() const = 0;
};
class DeckFileNotFound : public Exception {
public:
    string what() const override {
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

    string what() const override {
        return errorMessage;
    }
};

class DeckFileInvalidSize : public Exception {
public:
    string what() const override {
        return "Deck File Error: Deck size is invalid";
    }
};


#endif